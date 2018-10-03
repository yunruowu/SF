#include <iostream> #include <fstream> using namespace std; int ff(int i) {  int x=1;   for(int j=1;j<=i;j++)   x*=j;  return x; }  int permRank(int n,int *pi) {  int rho[n],r=0;      for(int j=0; j<n; j++){   int count=0;    for(int i=0;i<j;i++){    if(pi[i]<pi[j])     count++;   }    rho[j]=pi[j]-1-count;   r+=rho[j]*ff(n-j-1);  }      return r; } 

void perSucc(int n, int *pi,int &flag) { //求下一排列  int i=n-2;   while(pi[i+1]<pi[i])   i--;     if(i==0) flag=0;  else {    flag=1;   int j=n-1;   int min;    for(int k=n-1;k>=i;k--){    min=pi[k];    if(pi[k]<min)    j--;         }        swap(pi[i],pi[j]);       for(int m=i+1; m<=(i+n)/2; m++)    swap(pi[m],pi[n-m+i]);  } }  int main() {     freopen("out_data.txt","w",stdout);  freopen("in_data.txt","r",stdin);    int n=0,r=0,flag;     cin>>n;     int pi[n];   for(int i=0; i<n; i++)       cin>>pi[i];         cout<<permRank(n,pi)<<endl;     perSucc(n, pi,flag);    if(flag==0)    cout<<"无下一排列！"<<endl;