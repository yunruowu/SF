#include <stdio.h>
 
int map[1000][1000];
int index =1;
 
int horse[6][150]={{1,30,33,16,3,24,32,17,2,23,34,15,29,36,31,14,25,4,18,9,6,35,22,13,7,28,11,20,5,26,10,19,8,27,12,21}
					,{1,10,31,40,21,14,29,38,32,41,2,11,30,39,22,13,9,48,33,20,15,12,37,28,42,3,44,47,6,25,18,23,45,8,5,34,19,16,27,36,4,43,46,7,26,35,24,17}
					,{1,46,17,50,3,6,31,52,18,49,2,7,30,51,56,5,45,64,47,16,27,4,53,32,48,19,8,29,10,55,26,57,63,44,11,22,15,28,33,54,12,41,20,9,36,23,58,25,43,62,39,14,21,60,37,34,40,13,42,61,38,35,24,59}
					,{1,46,37,66,3,48,35,68,5,8,38,65,2,47,36,67,4,7,34,69,45,80,39,24,49,18,31,52,9,6,64,23,44,21,30,15,50,19,70,33,79,40,25,14,17,20,53,32,51,10,26,63,22,43,54,29,16,73,58,71,41,78,61,28,13,76,59,56,11,74,62,27,42,77,60,55,12,75,72,57}
					,{1,54,69,66,3,56,39,64,5,8,68,71,2,55,38,65,4,7,88,63,53,100,67,70,57,26,35,40,9,6,72,75,52,27,42,37,58,87,62,89,99,30,73,44,25,34,41,36,59,10,74,51,76,31,28,43,86,81,90,61,77,98,29,24,45,80,33,60,11,92,50,23,48,79,32,85,82,91,14,17,97,78,21,84,95,46,19,16,93,12,22,49,96,47,20,83,94,13,18,15}
					,{1,4,119,100,65,6,69,102,71,8,75,104,118,99,2,5,68,101,42,7,28,103,72,9,3,120,97,64,41,66,25,70,39,74,105,76,98,117,48,67,62,43,40,27,60,29,10,73,93,96,63,44,47,26,61,24,33,38,77,106,116,51,94,49,20,23,46,37,30,59,34,11,95,92,115,52,45,54,21,32,35,80,107,78,114,89,50,19,22,85,36,55,58,31,12,81,91,18,87,112,53,16,57,110,83,14,79,108,88,113,90,17,86,111,84,15,56,109,82,13}
					};
void Print(int m,int n,int x,int y,int M,int N,int flag)
{ 
	for(int i =x;i<m+x;i++)
	{
		for(int j = y;j<n+y;j++)
			if(m<=n) 
			{
				if(flag == 1 ) 
				{
					map[i][j]=horse[(m-6)/2+(n-6)/2][(i-x)*n+(j-y)];
				}
				else if(flag == 2)
				{
					int index = horse[(m-6)/2+(n-6)/2][2*n+m-2];
					int end = horse[(m-6)/2+(n-6)/2][m-1];
					int number = horse[(m-6)/2+(n-6)/2][(i-x)*n+(j-y)];	
					if(index>end)
						map[i][j] = (number-index+m*n)%(m*n)+1+map[x+1][y+n];
						//map[i][j] = (number-index+m*n)%(m*n)+1;
					else
						map[i][j] = (m*n)-(number-index+m*n)%(m*n)+1+map[x+1][y+n];
				//	map[i][j] = map[x+1][y+n];
				}
				else if(flag == 3)
				{
					int index = horse[(m-6)/2+(n-6)/2][(m-3)*n+1];
					int end = horse[(m-6)/2+(n-6)/2][(m-1)*n];
					int number = horse[(m-6)/2+(n-6)/2][(i-x)*n+(j-y)];	
					if(index>end)
						map[i][j] = (number-index+m*n)%(m*n)+1+map[x+m-2][y-1];
						//	map[i][j] = (number-index+m*n)%(m*n)+1;
					else
					//	map[i][j] = (m*n)-(number-index+m*n)%(m*n)+1+map[x+m-2][y-1];
					//	map[i][j] = (number-index+m*n)%(m*n)+1;
						map[i][j] = (index-number+m*n)%(m*n)+1+map[x+m-2][y-1];
				}
				else if(flag == 4)
				{
					int index = horse[(m-6)/2+(n-6)/2][2];
					int end = horse[(m-6)/2+(n-6)/2][n];
					int number = horse[(m-6)/2+(n-6)/2][(i-x)*n+(j-y)];	
					if(index>end)
						map[i][j] = (number-index+m*n)%(m*n)+1+map[x-1][y];
					else
						map[i][j] = (m*n)-(number-index+m*n)%(m*n)+1+map[x-1][y];
				}
				else
					map[i][j]=horse[(m-6)/2+(n-6)/2][(i-x)*n+(j-y)];
			}
			else
			{
				map[i][j]=horse[(m-6)/2+(n-6)/2][(i-x)+(j-y)*m];
				
			}
			//map[i][j]=index;
	}
	if(flag == 1)
	{
		for(int i =x;i<m+x;i++)
			for(int j = y;j<n+y;j++)
				if(map[i][j]>map[x+m-2][y+n-1])
					map[i][j]=M*N-m*n+map[i][j]; 	
	} 
	index++;
}
 
void fun(int m,int n,int x,int y,int M,int N,int flag)
{
 
	//printf("\n======================>%d %d %d %d %d\n",m,n,x,y,flag);
	if(m<=10 || n<=10)
		Print(m,n,x,y,M,N,flag); 
	else
	{
		if(m%4==0)
		{
			if(n%4==0)
			{
				fun(m/2,n/2,x,y,m,n,1);			//左上 
				fun(m/2,n/2,x,y+n/2,m,n,3);		//右上 
				fun(m/2,n/2,x+m/2,y+n/2,m,n,4);	//右下 
				fun(m/2,n/2,x+m/2,y,m,n,2);		//左下 
			  }
			else
			{
				fun(m/2,n/2-1,x,y,m,n,1);              //左上 
				fun(m/2,n/2-1,x+m/2,y,m,n,2);          //左下 
				fun(m/2,n/2+1,x,y+n/2-1,m,n,3);        //右上 
			 	fun(m/2,n/2+1,x+m/2,y+n/2-1,m,n,4);    //右下 
			}
		}
		else
		{
			if(n%4==0)
			{
				fun(m/2-1,n/2,x,y,m,n,1);             //左上 
				fun(m/2+1,n/2,x+m/2-1,y,m,n,2);       //左下 
				fun(m/2+1,n/2,x,y+n/2,m,n,3);         //右上 
				fun(m/2+1,n/2,x+m/2-1,y+n/2,m,n,4);   //右下 
			}
			else
			{    
				fun(m/2-1,n/2-1,x,y,m,n,1);           //左上 
				fun(m/2+1,n/2-1,x+m/2-1,y,m,n,2);     //左下 
				fun(m/2-1,n/2+1,x,y+n/2-1,m,n,3);       //右上 
				fun(m/2+1,n/2+1,x+m/2-1,y+n/2-1,m,n,4);   //右下 
			}
		}
	}
		
}
 
 
int main()
{
	int m,n;
	while(~scanf("%d%d",&m,&n))
//	m=16;n=16; 
	{
		int i;
		for(i = 0;i<m;i++)
			for(int j = 0;j<n ;j++)
				map[i][j] = 0;
		index = 1;
		fun(m,n,0,0,m,n,-1);
		for(i = 0;i<m;i++)
		{ 
			for(int j = 0;j<n;j++)
			{
				printf("%6d",map[i][j]);
			}
			printf("\n");
		} 
	}
	return 0;
}
