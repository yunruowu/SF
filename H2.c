#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int map[100][100];
int vis[100][100],ok=0,n;
struct node{int x,y;};
struct NEXT{int num,dire;};
vector<node>Road;
bool cmp(NEXT n1,NEXT n2){
	return n1.num<n2.num;
}
bool check(int x,int y){
	return x>=0&&x<n&&y>=0&&y<n;
}
int dir[8][2]={2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2,1,2,2,1};
int getdir(int x,int y){                            //计算从(x,y)出发，能达到多少个点
    int res=0;
    for(int i=0;i<8;i++){
        int x1=x+dir[i][0];
        int y1=y+dir[i][1];
        if(check(x1,y1)&&!vis[x1][y1])
			res++;
    }
    return res;
}
void dfs(int x,int y,int steps){
    if(x<0||x>=n||y<0||y>=n||vis[x][y]||ok)
		return;
    vis[x][y]=1;
	steps++;
    Road.push_back((node){x,y});
	int lc = 0;
    if(steps==n*n){
        for(int i=0;i<Road.size();i++){
			map[Road[i].x][Road[i].y]=lc;
			lc++;
			//cout<<char(Road[i].x+'1')<<" "<<char(Road[i].y+'1')<<"  ";
		}
		ok=1;Road.pop_back();vis[x][y]=0;return;
	}

    vector<NEXT>Dire;
    for(int i=0;i<8;i++){
        int x1=x+dir[i][0];
        int y1=y+dir[i][1];
        if(check(x1,y1)&&!vis[x1][y1]){
            int cnt=getdir(x1,y1);
            Dire.push_back((NEXT){cnt,i});
        }
    }
    sort(Dire.begin(),Dire.end(),cmp);              //按到达的难易程度进行排序
	for(int i=0;i<Dire.size();i++)
		dfs(x+dir[Dire[i].dire][0],y+dir[Dire[i].dire][1],steps);


    vis[x][y]=0;
    Road.pop_back();
}
int main(){
	cout<<"是的";
	while(cin>>n){
        ok=0;dfs(0,0,0);
        for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<map[i][j]<<"   ";
		
			cout<<i<<endl;
		}
        if(!ok)cout<<"IMPOSSIBLE\n";
    }
	
    return 0;
}
