#include <stdio.h>
#include <stdlib.h>  
typedef struct 
{
	 
	int x;
	int y; 

}Step;
	Step step[8] = {{-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}, { 2, 1}, { 1, 2}, {-1, 2}, {-2, 
1}}; 

int JumpStep(int ** &chess,int x, int y,int M,int N) 

	{
 
    if (x >= 0 && x < M && y >= 0 && y < N && chess[x][y] == 0) 
        return 1; 
    return 0; 
} 
 
int DegreeStep(int ** &chess,int x, int y,int M,int N) 
{ 
    int degree = 0; 
    for (int i = 0; i < 8; ++i) 
    { 
        if (JumpStep(chess,x + step[i].x, y + step[i].y, M, N)) 
            degree++; 
    } 
    
return degree; 
} 
void inssort(int * a, int * b, int n) 
{ 
    if (n <= 0) 
  return; 
 
 int temp; 
 
    for (int i = 0; i < n; ++i) 
    { 
        for (int j = i; j > 0; --j) 
        { 
            if (a[j] < a[j - 1]) 
            { 
                temp = a[j - 1]; 
                a[j - 1] = a[j]; 
                a[j] = temp; 
 
                temp = b[j - 1]; 
                b[j - 1] = b[j]; 
                b[j] = temp; 
    
			}
		}
	} 
} 
 
bool FindStart(int x, int y,int midx,int midy) 
{ 
    for (int i = 0; i < 8; ++i) 
        if (x + step[i].x == midx && y + step[i].y == midy) 
            return 1; 
    return 0; 
} 
 
void BackTrace(int ** &chess,int M,int N,int t, int x, int y, int xstart, int ystart) 
{ 
 int midx,midy; 
  
 midx = M / 2 - 1; 
 midy = N / 2 - 1; 
    if (t >= M * N && FindStart(x,y,midx,midy)) 
    { 
		int max, i, j, k; 
 
		 max = M * N; 
		k = max - chess[xstart][ystart]; 
		for (i = 0; i < M; ++i) 
		{ 
			printf("\n\n"); 
			for (j = 0; j < N; ++j) 
			{ 
				chess[i][j] = (chess[i][j] + k) % max + 1; 
				printf("%5d", chess[i][j]); 
			} 
		} 
		printf("\n\n"); 
   
		for (i = 0; i < M; i++) 
			free(*(chess + i)); 
		free(chess); 
		chess = NULL; 
			exit(1); 
    } 
    else 
    { 
		int power[8],NextSteps[8];
		int nx,ny,mx,my; 
		int k = 0;
   
        for (int i = 0; i < 8; ++i) 
        {
 
            if (JumpStep(chess,x + step[i].x, y + step[i].y, M, N)) 
            {
 
                power[k] = DegreeStep(chess, x + step[i].x, y + step[i].y,M,N); 
                NextSteps[k++] = i; 
            } 
        } 
         
        inssort(power, NextSteps, k); 
 
        for (int i = 0; i < k; ++i) 
        {
 
			int d; 
 
			if(k == 1) 
				d = NextSteps[i]; 
			else 
			{ 
				d = NextSteps[i]; 
				for (int j = i; j < k-1; j++) 
				{ 
					if (power[j] == power[j+1]) 
					{ 
							nx = x + step[NextSteps[j]].x; 
							ny = y + step[NextSteps[j]].y; 
							mx = x + step[NextSteps[j+1]].x; 
							my = y + step[NextSteps[j+1]].y; 
							if ((abs(mx - midx) + abs(my - midy)) > (abs(nx - midx)+ abs(ny - midy))) 
								d = NextSteps[j+1]; 
							else 
								d = NextSteps[j]; 
					} 
					else 
						break;       
      
					} 
			}
			x += step[d].x;
			y += step[d].y; 
			chess[x][y] = t + 1; 
			BackTrace(chess, M, N, t + 1, x, y, xstart, ystart); 
			chess[x][y] = 0; 
			x -= step[d].x; 
			y -= step[d].y; 
 
			 
		} 
	} 
}
void Traver(int M,int N,int x,int y) 
{ 
 int midx, midy, i, j; 
 int ** chess; 
  
 chess = (int **) malloc (M * sizeof(int)); 
 if (chess == NULL) 
 {
 
  printf("内存分配失败\n"); 
  exit(-1); 
 } 
 for (i = 0; i < M; i++) 
 { 
  *(chess + i) = (int *) malloc (N * sizeof(int)); 
  if (*(chess + i) == NULL) 
  { 
   printf("内存分配失败\n"); 
   exit(-1); 
  } 
 } 
 for (i = 0; i < M; i++) 
  for (j = 0; j < N; j++) 
		chess[i][j] = 0; 
 midx = M / 2 -1; 
 midy = N / 2 -1; 
    chess[midx][midy] = 1; 
 
    BackTrace(chess, M, N, 1, midx, midy, x, y); 
 
 for (i = 0; i < M; i++) 
	 free(*(chess+i));
 free(chess);
 chess = NULL; 
} 
 
int main(void) 
{ 
 int m, n; 
 int x, y; 
 
 printf("请输入棋盘大小m*n|m-n|<=2且m和n都为偶数\n"); 
 scanf("%d %d",&m,&n); 
 printf("请输入起始位置（x,y）",m,n); 
 scanf("%d %d",&x,&y); 
 
 Traver(m,n,x,y); 
 
 return 0; 
}
 
 
