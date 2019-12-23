#include<iostream>
#include<cstring>
using namespace std;

const int N=5000;
int a[N+1][N+1];
int n,m;

int input()
{
  cin >> n >> m;
  for(int i=1;i<=m;i++)
   { int v,w; cin >> v >> w;
     a[v][w]=a[w][v]=1;
   }
}

int v[N];
int c;
void dfs(int j)
{
  v[j]=1; c++;
  for(int i=1;i<=n;i++)
   if(!v[i])
    if(a[j][i]==1) dfs(i);
}

int counter=0;
void dodfs()
{
  for(int i=1;i<=N;i++)
  for(int j=i+1;j<=N;j++)
  if(a[i][j]==1)
  {
    memset(v,0,sizeof(int)*N);
    c=0;
    dfs(i);
    int d=c;
    a[i][j]=a[j][i]=0;
    memset(v,0,sizeof(int)*N);
    c=0;
    dfs(i);
    if(c!=d) counter++;
    a[i][j]=a[j][i]=1;
   }
}

int main()
{
 input();
 dodfs();
 cout << counter << endl;
}
