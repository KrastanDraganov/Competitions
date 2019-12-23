#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
string s, word;
queue<int> q;
int a[128][128], used[128], m, n, ans;

void BFS()
{
   q.push(0);
   used[0]=-2;
   for(;!q.empty();)
   {
       int x=q.front();
       q.pop();
       if (x==m) break;
       for (int i=x+1; i<=m; i++)
       {
           if (a[x][i]==1 && used[i]==-1)
           {
               used[i]=x;
               q.push(i);
           }
       }
   }
}

void Print()
{
    int x=m;
    while (used[x]!=0)
    {
        x=used[x];
        s.insert(x," ");
        ans++;
    }
}

int main()
{
    cin>>s;
    m=s.size();
    for (int i=0; i<=m; i++)
        used[i]=-1;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>word;
        int k=word.size();
        for (int j=0; j<=m-k; j++)
        {
            if (s.substr(j, k)==word)
                a[j][j+k]=1;
        }
    }
    BFS();
    Print();
    cout<<ans+1<<endl;
    cout<<s<<endl;
    return 0;
}
