#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<vector<int> >t(101, vector<int>(101));
int m,n;


set<vector<vector<int> > >s;


void show(vector<vector<int> > &t)
{
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++) cout << t[i][j];
    cout << endl;
  }
  cout << endl;
}

int c;
int L;
void run()
{
  if(L==(m*n)/2)
  {
    //show(t);
    //cout << endl;

    if(s.count(t)==0)
    {
      s.insert(t);
      c++;
    }

  }

  for(int i=1; i<=m; i++)
  for(int j=1; j<=n; j++)
   if(t[i][j]==0)
   {
     if(i<m)if(t[i+1][j]==0)
     {L++;
      t[i][j]=t[i+1][j]=1; run();
      t[i][j]=t[i+1][j]=0;
      L--;
     }
     if(j<n)if(t[i][j+1]==0)
     {L++;
      t[i][j]=t[i][j+1]=2; run();
      t[i][j]=t[i][j+1]=0;
      L--;
     }
   }
}


int main()
{

  cin >> m >> n;

  run();

  //for(auto t:s) show(t);

  //cout << endl;
  cout << s.size() << endl;
}
