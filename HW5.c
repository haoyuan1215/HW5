#include <stdio.h>
int point(int chess[8][8],int x,int y,int next[8][8],int next1[8][8],int next2[8][8])  {
    int n=1,m=1;
    for(int a=0;a<8;a++){
        for(int b=0;b<8;b++) {
            next[a][b]=0;
        }
    }
    for(int a=0;a<8;a++){
        for(int b=0;b<8;b++) {
            next1[a][b]=0;
        }
    }
    for(int a=0;a<8;a++) {
        for(int b=0;b<8;b++) {
            next2[a][b]=0;
        }
    }
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if (chess[i][j]==1) {
                for(int dx=-1;dx<=1;dx++) {
                    for(int dy=-1;dy<=1;dy++) {
                        n=1;
                        if(chess[i+dx][j+dy]==2) {
                            while(chess[i+n*dx][j+n*dy]==2) {
                                if(i+n*dx<0||i+n*dx>=8||j+n*dy<0||j+n*dy>=8||chess[i+n*dx][j+n*dy]==0) {
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
                                    n=1;
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

int play(int chess[8][8],int x,int y) {
    int m=1;
    chess[x][y]=1;
    for(int dx=-1;dx<=1;dx++) {
        for(int dy=-1;dy<=1;dy++) {
            m=1;
            if(chess[x+dx][y+dy]==2) {
                while(chess[x+m*dx][y+m*dy]!=0) {
                    if(chess[x+m*dx][y+m*dy]==2) {
                        m++;
                    }
                    else if(chess[x+m*dx][y+m*dy]==1) {
                        for(int a=1;a<m;a++) {
                            chess[x+a*dx][y+a*dy]=1;
                        }
                        break;
                    }
                    else {
                        m=0;
                        break;
                    }
                }
            }
        }
    }
}
int main() {
    int i=0,j=0;
    int chess[8][8]={};
    int next [8][8]={};
    int next1[8][8]={};
    int next2[8][8]={};
    for(int m=0;m<8;m++){
        for(int n=0;n<8;n++){
            scanf("%d",&chess[m][n]);
        }
    }
    for(int m=0;m<8;m++){
        for(int n=0;n<8;n++){
            printf("%d ",chess[m][n]);
        }
        printf("\n");
    }

    point(chess,i,j,next,next1,next2);
    printf("\n黑子可下位子\n");
    for(int a=0;a<8;a++) {
        for(int b=0;b<8;b++) {
            if(next1[a][b]==1) {
                printf("(%d,%d)",a,b);
            }
        }
    }
    printf("\n");
    scanf("%d%d",&i,&j);
    play(chess,i,j);
    for(int m=0;m<8;m++){
        for(int n=0;n<8;n++){
            printf("%d ",chess[m][n]);
        }
        printf("\n");
    }
    return 0;
}
