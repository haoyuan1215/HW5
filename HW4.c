#include <stdio.h>
int point(int chess[8][8],int i,int j,int next[8][8],int next1[8][8],int next2[8][8])  {
    int n=1;
    for(int a=0;a<8;a++)
        {for(int b=0;b<8;b++) {
            next[a][b]=0;
        }
    }
    for(int a=0;a<8;a++)
        {for(int b=0;b<8;b++) {
            next1[a][b]=0;
        }
    }
    for(int a=0;a<8;a++)
        {for(int b=0;b<8;b++) {
            next2[a][b]=0;
        }
    }
    if(chess[i][j]==1) {
        
        for(int dx=-1;dx<=1;dx++) {
            for(int dy=-1;dy<=1;dy++) {
                if(chess[i+dx][j+dy]==2) {
                    while(chess[i+n*dx][j+n*dy]!=0) {
                        if(i+n*dx<0||i+n*dx>=8||j+n*dy<0||j+n*dy>=8||chess[i+n*dx][j+n*dy]==1) {
                            n=0;
                            break;
                        }
                        else {
                            n++;
                        }
                    }
                    if(n>0) {
                        next[i+n*dx][j+n*dy]=1;
                    }
                }
            }
        }
    }
    else if (chess[i][j]==2) {
        for(int dx=-1;dx<=1;dx++) {
            for(int dy=-1;dy<=1;dy++) {
                if(chess[i+dx][j+dy]==1) {
                    while(chess[i+n*dx][j+n*dy]!=0) {
                        if(i+n*dx<0||i+n*dx>=8||j+n*dy<0||j+n*dy>=8||chess[i+n*dx][j+n*dy]==2) {
                            n=0;
                            break;
                        }
                        else {
                            n++;
                        }
                    }
                    if(n>0) {
                        next[i+n*dx][j+n*dy]=2;
                    }
                }
            }
        }
    }
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if (chess[i][j]==1) {
                for(int dx=-1;dx<=1;dx++) {
                    for(int dy=-1;dy<=1;dy++) {
                        if(chess[i+dx][j+dy]==2) {
                            while(chess[i+n*dx][j+n*dy]!=0) {
                                if(i+n*dx<0||i+n*dx>=8||j+n*dy<0||j+n*dy>=8||chess[i+n*dx][j+n*dy]==1) {
                                    break;
                                }
                                else {
                                    n++;
                                }
                            }
                            next1[i+n*dx][j+n*dy]=1;
                        }
                    }
                }
            }
            if (chess[i][j]==2) {
                for(int dx=-1;dx<=1;dx++) {
                    for(int dy=-1;dy<=1;dy++) {
                        if(chess[i+dx][j+dy]==1) {
                            while(chess[i+n*dx][j+n*dy]!=0) {
                                if(i+n*dx<0||i+n*dx>=8||j+n*dy<0||j+n*dy>=8||chess[i+n*dx][j+n*dy]==2) {
                                    n=0;
                                    break;
                                }
                                else {
                                    n++;
                                }
                            }
                            next2[i+n*dx][j+n*dy]=2;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    int i,j,color;
    int chess[8][8]
    int next[8][8]={};
    int next1[8][8]={};
    int next2[8][8]={};
    for(int m=0;m<8;m++){
        for(int n=0;n<8;n++){
            scanf("%d",&chess[m][n]);

        }
    }
    scanf("%d%d",&i,&j);
    point(chess,i,j,next,next1,next2);
    color=chess[i][j];
    if(color==1||color==2) {
        for(int a=0;a<8;a++) {
            for(int b=0;b<8;b++) {
                if(next[a][b]==color) {
                printf("(%d,%d)",a,b);
                }
            }
        }
    }
    else if(color==0) {
        printf("空\n");
    }
    printf("\n黑子可下位子\n");
    for(int a=0;a<8;a++) {
        for(int b=0;b<8;b++) {
            if(next1[a][b]==1) {
                printf("(%d,%d)",a,b);
            }
        }
    }
    printf("\n白子可下位子\n");
    for(int a=0;a<8;a++) {
        for(int b=0;b<8;b++) {
            if(next2[a][b]==2) {
                printf("(%d,%d)",a,b);
            }
        }
    }
    return 0;
}
