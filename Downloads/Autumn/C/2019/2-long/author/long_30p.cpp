#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int maxc;
int n;
int K;

vector<string>a;


void case1()
{
    vector<int>t(maxc,0);
    for(int i=0;i<n;i++)
    {string v; cin >> v; a.push_back(v);}

    for(int i=0;i<n;i++)
    {
      vector<int>b(maxc,0);
      for(int j=0;j<a[i].size();j++)
       {int v = (a[i][j]-'a'); b[v]=1;}
      for(int k=0;k<maxc;k++) t[k] = t[k]+b[k];
    }

    int m=0;int k0=-1;
    for(int k=0;k<maxc;k++)
    if(m<t[k]) {m=t[k]; k0=k;}

    cout << m << endl;
    cout << char(k0+'a') << endl;

    int br=0;
    for(int k=0;k<maxc;k++)
    if(m==t[k]) br++;

    cout << br << endl;
}

void case2()
{

    vector<int>t(maxc*maxc,0);
    for(int i=0;i<n;i++)
    {string v; cin >> v; a.push_back(v);}

    for(int i=0;i<n;i++)
    {
      vector<int>b(maxc*maxc,0);
      for(int j1=0;j1<a[i].size();j1++)
      for(int j2=j1+1;j2<a[i].size();j2++)
      if(a[i][j1]!=a[i][j2])
       {int v = maxc*(a[i][j1]-'a')+ (a[i][j2]-'a'); b[v]=1;}
      for(int k=0;k<maxc*maxc;k++) t[k] = t[k]+b[k];
    }

    int m=0;int k0=-1;
    for(int k=0;k<maxc*maxc;k++)
    if(m<t[k]) {m=t[k]; k0=k;}

    cout << m << endl;
    cout << char(k0/maxc+'a') << char(k0%maxc+'a') << endl;

    int br=0;
    for(int k=0;k<maxc*maxc;k++)
    if(m==t[k]) br++;

    cout << br << endl;

}

void case3()
{
  vector<int>t(maxc*maxc*maxc);

  for(int i=0;i<n;i++)
    {
      vector<int>b(maxc*maxc*maxc,0);
     for(int j1=0;j1<a[i].size();j1++)
      for(int j2=j1+1;j2<a[i].size();j2++)
      for(int j3=j2+1;j3<a[i].size();j3++)
      if(a[i][j1]!=a[i][j2])
      if(a[i][j2]!=a[i][j3])
      if(a[i][j3]!=a[i][j1])
      {
          int v = maxc*maxc*(a[i][j1]-'a') + maxc*(a[i][j2]-'a') + (a[i][j3]-'a');
          b[v]=1;
      }


     for(int k=0;k<maxc*maxc*maxc;k++) t[k] = t[k]+b[k];
    }

    int m=0;int k0=-1;
    for(int k=0;k<maxc*maxc*maxc;k++)
    if(m<t[k])
      {m=t[k]; k0=k;}

    if(k0==-1){cout << 0 << endl; exit(0);}
    cout << m << endl;
    cout << char(k0/(maxc*maxc) + 'a') << char((k0/maxc)%maxc + 'a') << char(k0%maxc+'a') << endl;

    int br=0;
    for(int k=0;k<maxc*maxc*maxc;k++)
     if(t[k]==m)
    {
      br++;

    }

    cout << "br=" << br << endl;
}

int main()
{
    cin >> n >> maxc >> K;
    if(K==1) case1();
    else if(K==2) case2();
    else case3();
}


