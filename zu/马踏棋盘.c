#include<stdio.h> 
#include<stdlib.h> 
#include<memory.h> 
#define M 2048 
int m,n; //棋盘的大小
int L,C;//起始的位置
FILE *fin; //读入最初的分块
int count=1;
typedef struct 
{ 
 int x,y; 
}chese; //给出小棋盘的路径

chese b66[36],b68[48],b86[48],b88[64],b810[80],b108[80],b1010[100],b1012[120],b1210[120]; //6*6 6*8 8*6 …12*10

chese link[500][500]; 
int a[10][12]; //用来读入小棋盘路径的数组
void step(int m,int n,chese b[]) //将a[][]的内容输入到分块中。
{ 
 int i,j,k=m*n,p; 
 if(m<n) 
 { 
	for(i=0;i<m;i++) 
	{ 
		for(j=0;j<n;j++) 
		{ 
			p=a[i][j]-1; 
			b[p].x=i; 
			b[p].y=j; 
		} 
	} 
 } 
 else 
 { 
	for(i=0;i<m;i++) 
	{ 
		for(j=0;j<n;j++) 
		{ 
			p=a[j][i]-1; 
			b[p].x=i; 
			b[p].y=j; 
		}
	}	 
 } 
}      
void input() //输入函数
{		
	 int i;
	 int j; 
	 printf("请输入棋盘规格 (格式为n,例如6)"); 
	 scanf("%d",&n);
	 printf("请输入马的初始位置，L和C");
	 scanf("%d%d",&L,&C);
	 m = n;
	 fin=fopen("12.txt","r"); //打开小棋盘路径的文件 
	 
	 
	 
	
	 //6*6 
	 for(i=0;i<6;i++)//读入mn的基本的回路 
		for(j=0;j<6;j++) 
			fscanf(fin,"%d",&a[i][j]); 
	 step(6,6,b66); 
	 
	 //6*8 8*6
	 for(i=0;i<6;i++) 
	  for(j=0;j<8;j++) 
	   fscanf(fin,"%d",&a[i][j]); 
	 step(6,8,b68);
	 step(8,6,b86);
	 
	 //8*8
	 for(i=0;i<8;i++) 
	  for(j=0;j<8;j++) 
	   fscanf(fin,"%d",&a[i][j]); 
	 step(8,8,b88); 
	 
	 //8 10
	 for(i=0;i<8;i++) 
	  for(j=0;j<10;j++) 
	  fscanf(fin,"%d",&a[i][j]); 
	 step(8,10,b810); 
	 step(10,8,b108); 
	 
	 //10 10
	 for(i=0;i<10;i++) 
	  for(j=0;j<10;j++) 
	   fscanf(fin,"%d",&a[i][j]); 
	 step(10,10,b1010); 
	 
	 //10 12
	 for(i=0;i<10;i++) 
	  for(j=0;j<12;j++) 
	   fscanf(fin,"%d",&a[i][j]); 
	 step(10,12,b1012); 
	 step(12,10,b1210); 
	 
	 //读入起始位置 
	 scanf("请输入起始位置：%d%d",&L,&C);
} 	
int pos(int x,int y,int col) 
{ 
 	return col*x+y; 
}      
void build(int m,int n,int offx,int offy,int col,chese b[]) 
{ 
 	int i,p,q,k=m*n,x1,x2,y1,y2; 
 	for(i=0;i<k;i++) 
 	{	
		count++;
		x1=offx+b[i].x; 
		y1=offy+b[i].y; 
		x2=offx+b[(i+1)%k].x; 
		y2=offy+b[(i+1)%k].y;  
		p=pos(x1,y1,col); 
		q=pos(x2,y2,col); 
		link[x1][y1].x=q; 
		link[x2][y2].y=p; 
 	} 
} 
void Base(int mm,int nn,int offx,int offy) 
{	
 	if(mm==6&&nn==6)
	 	build(mm,nn,offx,offy,n,b66); 
 	else if(mm==6&&nn==8)
	 	build(mm,nn,offx,offy,n,b68); 
 	else if(mm==8&&nn==6)
	 	build(mm,nn,offx,offy,n,b86); 
 	else if(mm==8&&nn==8)
	 	build(mm,nn,offx,offy,n,b88); 
 	else if(mm==8&&nn==10)
	 	build(mm,nn,offx,offy,n,b810); 
 	else if(mm==10&&nn==8)
	 	build(mm,nn,offx,offy,n,b108); 
 	else if(mm==10&&nn==10)	
	 	build(mm,nn,offx,offy,n,b1010); 
 	else if(mm==10&&nn==12)
	 	build(mm,nn,offx,offy,n,b1012); 
 	else if(mm==12&&nn==10)
	 	build(mm,nn,offx,offy,n,b1210); 
} 
bool comp(int mm,int nn,int offx,int offy) 
{ 
 	int mm1,mm2,nn1,nn2,i,j1,j2; 
 	int x[8],y[8],p[8]; 
 	/*if(mm%2||nn%2||mm-nn>2||nn-mm>2||mm<6||nn<6) //不满足条件，自动结束
	 	return true;
	*///调用基本的棋盘 
 	if(mm<12||nn<12)
 	{
  		Base(mm,nn,offx,offy); 
  		return false; 
 	}
	//划分棋盘 
	
	//分列 
  	mm1=mm/2; 
  	if(mm%4>0)	
	  	mm1--; 
  	mm2=mm-mm1;
	  
	//分行  
  	nn1=nn/2; 
  	if(nn%4>0)	
	  	nn1--; 
  	nn2=nn-nn1;
	  
	//递归调用，开始分治 
  	comp(mm1,nn1,offx,offy); 
  	comp(mm1,nn2,offx,offy+nn1); 
  	comp(mm2,nn1,offx+mm1,offy); 
  	comp(mm2,nn2,offx+mm1,offy+nn1); 
  	x[0]=offx+mm1-1;y[0]=offy+nn1-3; 
  	x[1]=x[0]-1;y[1]=y[0]+2; 
  	x[2]=x[1]-1;y[2]=y[1]+2; 
  	x[3]=x[2]+2;y[3]=y[2]-1; 
  	x[4]=x[3]+1;y[4]=y[3]+2; 
  	x[5]=x[4]+1;y[5]=y[4]-2; 
 	x[6]=x[5]+1;y[6]=y[5]-2; 
  	x[7]=x[6]-2;y[7]=y[6]+1; 
  	for(i=0;i<8;i++) 
   		p[i]=pos(x[i],y[i],n); 
  	for(i=1;i<8;i+=2) 
  	{ 
	   j1=(i+1)%8; 
	   j2=(i+2)%8; 
	   if(link[x[i]][y[i]].x==p[i-1]) 
	    	link[x[i]][y[i]].x=p[j1]; 
	   else 
	    	link[x[i]][y[i]].y=p[j1]; 
	   if(link[x[j1]][y[j1]].x==p[j2]) 
	    	link[x[j1]][y[j1]].x=p[i]; 
	   else 
	    	link[x[j1]][y[j1]].y=p[i]; 
	} 
  	return false; 
} 
void output() 
{ 
	 int i=0,j=0,k=2,x,y,p; 
	 int b[500][500]; 
	 if(comp(m,n,0,0))//直接退出 
	  	return; 
	 for(i=0;i<m;i++) //b[][]置零 
	  	for(j=0;j<n;j++) 
	   		b[i][j]=0; 
	 b[0][0]=1; //起始 
	 for(p=1;p<m*n;p++) 
	 { 
		  x=link[i][j].x; 
		  y=link[i][j].y; 
		  i=x/n; 
		  j=x%n;
		  if(b[i][j])
		  { 
			   i=y/n; 
			   j=y%n; 
		  } 
		  b[i][j]=k++; 
	 }  
	 b[1][2]=1;
	 for(i=0;i<m;i++) 
	 {  
		  for(j=0;j<n;j++) 
		  { 
		   		printf("%6d",(b[i][j]+m*n-b[L][C])%(m*n)); //只求了一条路径，但是路径的闭合可以以任意一点为起点 
		  } 
	  	  printf("\n"); 
	 } 
} 
 
int main() 
{ 
 
	 input(); 
	 output(); 
	 printf("时间复杂%d\n",count);
	 return 0;
}
