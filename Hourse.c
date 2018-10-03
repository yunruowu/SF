/*************************************************************************
    > File Name: Hourse.c
    > Author: Yunruowu
    > Mail: xuyunyang12345@163.com
    > Created Time: 2018/9/27 23:43:37
 ************************************************************************/
/*
#include<stdio.h>

	int A[100][100]={0};
//left and up
void upl(int &x, int &y){
	if((x-1)<0||(y-1)<0||(A[x][y]==1)){
		x = x;
		y = y;
	}else{
		x = x-1;
		y = y-1;
	}
}

//right and up
void upr(int &x, int &y){
	if((x+1)>=8||(y-1)<0||(A[x][y]==1)){
		x = x;
		y = y;
	}else{
		x = x-1;
		y = y-1;
	}
}

//left and down
void downl(int &x, int &y){
	if((x-1)<0||(y+1)>=8||(A[x][y]==1)){
		x = x;
		y = y;
	}else{
		x = x-1;
		y = y-1;
	}
}

//right and down
void downr(int &x, int &y){
	if((x+1)>=8||(y+1)>=8||(A[x][y]==1)){
		x = x;
		y = y;
	}else{
		x = x-1;
		y = y-1;
	}
}

int main()
{	
	int N = 8;
	printf("Please input x and y\n");
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i = 0 ; i < N; i++){
		printf("     ");
		for(int j = 0; j < N; j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	upl(x,y);
	printf("%d %d",x, y);
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			upl(x,y);
			continue;
			upr(x,y);
			continue;
			downl(x,y);
			continue;
			downr(x,y);
		}
		A[x][y]=1;
	}
	for(int i = 0 ; i < N; i++){
		printf("     ");
		for(int j = 0; j < N; j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
return 0;
}*/

#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#define N 8
int cnt=1;     // 记录马的位置
int n=1;
int chess[N][N]={0};  //棋盘
int move[8][2]={ 
	{1,-2},{2,-1},
	{2,1},{1,2},
	{-1,2},{-2,1},
	{-2,-1},{-1,-2}
	}; 
void horse(int ,int );
void printhorse();
 
int main()           //主函数
{
	chess[0][0]=1;
	horse(0,0);
	return 0;
}
void horse(int x,int y)   //执行过程
{
	int i;
	int a,b;
	for(i=0;i<N;i++)
	{
		a=x+move[i][0];
		b=y+move[i][1];
		if(a>=0&&a<N&&b>=0&&b<N&&!chess[a][b])
		{
			 chess[a][b]=++cnt;
			if(cnt<N*N)
			{	horse(a,b); 
			
			}                     // 递归
			else{
				printhorse();
				exit(0);
 
				
			}    
				chess[a][b]=0;//修改ab的值归为0
				cnt--;
		}
	}
}
void printhorse()          //输出马踏棋盘
{
	int i,j;
	printf("输出第%d组解：\n",n++);
    for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",chess[i][j]);
	printf("\n");
	}
}
 
