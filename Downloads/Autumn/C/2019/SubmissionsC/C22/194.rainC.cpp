#include<bits/stdc++.h>
using namespace std;

typedef int ll;

ll nums[1000100],adnums[1000100];

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

ll n,m,x,k,res=0,now,num=0;

cin>>n;
for(int i=0;i<n;++i)cin>>nums[i];
cin>>m;
for(int i=0;i<m;++i){
  cin>>x>>k;
  adnums[x]+=k;
  }

vector<ll> ans,pos;
stack<ll> v;
int f;
for(int i=0;i<n;++i){
  now=nums[i]+adnums[i];
  if(v.empty() || now>v.top()){
    v.push(now);
    pos.push_back(i);
    num+=adnums[i];
    }
  }
while(!v.empty()){
  ans.push_back(v.top());
  v.pop();
  }
reverse(ans.begin(),ans.end());
for(int i=1;i<ans.size();++i){
  res+=min(ans[i-1],ans[i])*(pos[i]-pos[i-1]);
  }
ll pr=0,endp=pos[pos.size()-1],enda=ans[ans.size()-1];
if(ans.size()>=2)pr=ans[ans.size()-2];

//-------------------------------------------------

ans.clear();pos.clear();
for(int i=n-1;i>=0;--i){
  now=nums[i]+adnums[i];
  if(v.empty() || now>v.top()){
    v.push(now);
    pos.push_back(i);
    num+=adnums[i];
    }
  }
while(!v.empty()){
  ans.push_back(v.top());
  v.pop();
  }

reverse(ans.begin(),ans.end());

for(int i=1;i<ans.size();++i){
  res+=min(ans[i-1],ans[i])*(pos[i-1]-pos[i]);
  }

//cout<<endl;
//for(int i=0;i<ans.size();++i)cout<<ans[i]<<" ";cout<<endl;
//for(int i=0;i<pos.size();++i)cout<<pos[i]<<" ";cout<<endl;

if(pos[pos.size()-1]==endp){
  num-=adnums[endp];
  ll prn=0;
  if(ans.size()>=2)prn=ans[ans.size()-2];
  num-=min(adnums[endp],enda-max(prn,pr));
  }
else {
  res+=min(enda,ans[ans.size()-1])*(pos[pos.size()-1]-endp);
  }

cout<<num<<" "<<res<<endl;
//cout<<enda<<" "<<endp<<endl;

return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1

3
1 123 2
2
0 1
1 1

*/
