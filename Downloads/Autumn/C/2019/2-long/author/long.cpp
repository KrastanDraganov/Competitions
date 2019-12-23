#include<iostream>
#include<vector>
using namespace std;

int n, K;

int maxc=26;

int M;// = maxc^K

vector<int>t;

int pos(char c)
{
   return int(c)-'a';
}

void show(int v)
{
   int v0=v;
   string s="";
   for(int i=1;i<=K;i++)
   {
     s=char(v%maxc+'a')+s;
     v=v/maxc;
   }

   cout << s << endl;

}

string s;

int p[30];

void go(int lev, int v, vector<int> &b)
{
  if(lev>K)
  {
    b[v]=1;
    return;
  }

  for(int j=p[lev-1]+1;j<s.size();j++)
  {
    char w=s[j];
    bool f=false;
    for(int t=1;t<lev;t++) if(s[p[t]]==w) {f=true; break;}
    if(f) continue;
    p[lev]=j;
    int v0=v;
    v = maxc*v+pos(s[j]);
    go(lev+1,v,b);
    v=v0;
  }

}

int main()
{

   cin >> n >> maxc >> K;


   M=1;
   for(int i=1;i<=K;i++) M = M*maxc;



   t.resize(M+1);
   for(int i=0;i<=M;i++) t.push_back(0);

   p[0]=-1;
   for(int i=0;i<n;i++)
    {

      cin >> s;
      vector<int>b(M,0);
      go(1,0,b);
      for(int j=0;j<M;j++) t[j] = t[j]+b[j];
    }

    int m=0;int k0=-1;
    for(int k=0;k<M;k++)
     if(m<t[k]) {m=t[k]; k0=k;}


    if(k0==-1)
     {
        cout << 0 << endl;
        return 0;
     }
    cout << m << endl;

    int bc=0;
    for(int k=0;k<M;k++)
     if(t[k]==m)
    {
      bc++;

    }

    show(k0);
    cout << bc << endl;

}


