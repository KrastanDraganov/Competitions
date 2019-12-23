#include<iostream>
#include<iomanip>
using namespace std;


const int N=1002;
const int W=100002;
int t[N];
int d[N][W];


void run()
{
  int T, n;
  cin >> T >> n;
  for(int j=1;j<=n;j++) cin >> t[j];

  int w=0;
  for(int j=1;j<=n;j++) w += t[j];

  if(w<=T)
  {
    cout << 1 << endl; return;
  }
  if(w>2*T)
  {
    cout << 0 << endl; return;
  }


  for(int j=1;j<=T;j++)
   if(t[1]<=j) d[1][j]=t[1];

  for(int i=2;i<=n;i++)
  for(int j=1;j<=T;j++)
  {
    d[i][j]=d[i-1][j];
    if(j-t[i]>=0)
     if(t[i]+d[i-1][j-t[i]]>d[i-1][j])
      d[i][j]=t[i]+d[i-1][j-t[i]];
  }

  cout << (w-d[n][T]<=T) << endl;
}

int main()
{
  int g; cin >> g;
  for(int i=1;i<=g;i++)
  {
    run();

  }
}


