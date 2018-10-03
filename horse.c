/*************************************************************************
    > File Name: horse.c
    > Author: Yunruowu
    > Mail: xuyunyang12345@163.com
    > Created Time: 2018/9/29 19:59:24
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define N 8
int pos = 1;
int chese[N][N]={0};//初始化棋盘
int move[8][2]={
	{1,-2},{1,2},
	{-1,-2},{-1,2},
	{2,-1},{2,1},
	{-2,-1},{-2,1}
};
void horse(int x, int y);
void printhorse();
int main()
{
	chese[2][1]=1;
	horse(2,1);
return 0;
}

void horse(int x,int y){
	int i;
	int a,b;
	for(i = 0;i<N;i++){
		a = x + move[i][0];
		b = y + move[i][1];
		if(a>=0&&a<N&&b>=0&&b<N&&chese[a][b]==0){
			chese[a][b]=++pos;
			if(pos<N*N){
				horse(a,b);
			}
			else{
				printhorse();
				exit(-1);
			}
			chese[a][b]=0;
			pos--;
		}
	}
}


void printhorse(){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N;j++){
			printf("%d ",chese[i][j]);
		}
		printf("\n");
	}
}
