#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> nums;
vector<ll> d,dd;
ll dp1[100100],dp2[100100];
bool used[10000];

int main(){

ll n,m,x;

cin>>n>>m;
for(int i=0;i<n;++i){
  cin>>x;
  nums.push_back(x);
  }
for(int i=0;i<m;++i){
  cin>>x;
  if(x!=0)dd.push_back(x);
  }

//sort(d.begin(),d.end());
sort(dd.begin(),dd.end());

/*
for(int i=0;i<d.size();++i){
  if(used[i])continue;
  for(int j=i+1;j<d.size();++j){
    if(used[j])continue;
    if(d[j]/d[i]>1 && d[j]%d[i]==0)used[j]=1;
    }
  }
for(int i=0;i<d.size();++i){
  if(!used[i])dd.push_back(d[i]);
  }
*/
//for(int i=0;i<dd.size();++i)cout<<dd[i]<<" ";cout<<endl;

ll now;
dp1[0]=nums[0];
for(int i=0;i<n;++i){
  for(int j=0;j<dd.size();++j){
    now=i+dd[j];
    if(now>=n)break;
    if(dp1[now]<dp1[i]+nums[now])dp1[now]=dp1[i]+nums[now];
    }
  }
for(int i=1;i<n;++i)if(dp1[i]<dp1[i-1])dp1[i]=dp1[i-1];


dp2[n-1]=nums[n-1];
for(int i=n-1;i>=0;--i){
  for(int j=0;j<dd.size();++j){
    now=i-dd[j];
    if(now<0)break;
    if(dp2[now]<dp2[i]+nums[now])dp2[now]=dp2[i]+nums[now];
    }
  }
//for(int i=0;i<n;++i)cout<<dp2[i]<<" ";cout<<endl;

for(int i=n-2;i>=0;--i)if(dp2[i]<dp2[i+1])dp2[i]=dp2[i+1];

//for(int i=0;i<n;++i)cout<<dp1[i]<<" ";cout<<endl;
//for(int i=0;i<n;++i)cout<<dp2[i]<<" ";cout<<endl;

ll res=0;
for(int i=0;i<n-1;++i){
  if(dp1[i]+dp2[i+1]>res)res=dp1[i]+dp2[i+1];
  }

cout<<res<<endl;


return 0;
}
/*
3 3
0 22 1
1 2 3 7 8 14

9 2
0 0 0 0 0 0 0 0 0
3 2

9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4

4 2
34 1 1 3
0 2

*/
