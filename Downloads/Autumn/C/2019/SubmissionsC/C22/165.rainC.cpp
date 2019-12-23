#include<bits/stdc++.h>
using namespace std;

typedef int ll;

ll nums[1000100],adnums[1000100];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

ll n,m,x,k,res=0,now;

cin>>n;
for(int i=0;i<n;++i)cin>>nums[i];
cin>>m;
for(int i=0;i<m;++i){
  cin>>x>>k;
  adnums[x]+=k;
  res+=k;
  }

vector<ll> ans,pos;
stack<ll> v;
int f;
for(int i=0;i<n;++i){
  now=nums[i]+adnums[i];
  if(v.empty() || now>v.top()){v.push(now);pos.push_back(i);}
  }
while(!v.empty()){
  ans.push_back(v.top());
  v.pop();
  }

reverse(ans.begin(),ans.end());
f=ans.size();

for(int i=n-1;i>=0;--i){
  now=nums[i]+adnums[i];
  if(v.empty() || now>v.top()){v.push(now);pos.push_back(i);}
  }
while(!v.empty()){
  ans.push_back(v.top());
  v.pop();
  }

reverse(pos.begin()+f,pos.end());
//for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";cout<<endl;
//for(int i=0;i<pos.size();++i)cout<<pos[i]<<" ";cout<<endl;

ll res1=0,res2=adnums[pos[0]];
for(int i=1;i<ans.size();++i){
  res1+=min(ans[i-1],ans[i])*(pos[i]-pos[i-1]);
  res2+=adnums[pos[i]];
  }

ll ng=0,wh;
for(int i=0;i<ans.size();++i){
  if(ans[i]>ng){ng=ans[i];wh=i;}
  }

ll l=0,r=0;
if(wh!=0)l=ans[wh-1];
if(wh!=ans.size()-1)l=ans[wh+1];
res2-=min(adnums[pos[wh]],ans[wh]-max(l,r));

cout<<res2<<" "<<res1<<endl;

return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
