/*************************************************************************
    > File Name: Hourse.c
    > Author: Yunruowu
    > Mail: xuyunyang12345@163.com
    > Created Time: 2018/9/27 23:43:37
 ************************************************************************/

#include<stdio.h>

int main()
{
	int A[8][8]={0};
	printf("Please input x and y\n");
	int x,y;
	scanf("%d %d",&x,&y);
	for(int i = 0 ; i < 8; i++){
		printf("     ");
		for(int j = 0; j < 8; j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
return 0;
}
