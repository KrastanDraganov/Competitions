#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")

typedef long long ll;

map<string,int> gl;
map<string,bool> g;
string koe,str,strres="";
ll n,k,m,ng=0,brng=0;

string next(string a){
  if(a[a.size()-1]=='1'){
    ll cnt=0,i;
    for(int i=a.size()-1;i>=0;--i){
      if(a[i]=='0'){
        if(cnt==k)return "-";
        for(;i>=0;--i)if(a[i]=='1')break;
        //cout<<i<<endl;
        a[i]='0';
        ++cnt;
        for(int j=1;j<=cnt;++j)a[i+j]='1';
        return a;
        }
      else {++cnt;a[i]='0';}
      }
    }
  else {
    for(int i=a.size()-1;i>=0;--i)
      if(a[i]=='1'){
        a[i]='0';a[i+1]='1';
        return a;
        }
    }
  }

void constr(string a,string b){
  ll l;
  string ans="";
  for(int i=0;i<a.size();++i){
    if(a[i]=='1')ans=ans+b[i];
    }

  if(g[ans]==0){
    g[ans]=1;
    l=++gl[ans];

    if(l>ng){
      ng=gl[ans];
      strres=ans;
      brng=1;
      }
    else if(l==ng){
      if(ans<strres)strres=ans;
      ++brng;
      //cout<<strres<<" "<<ans<<endl;
      }
    }
  }

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);

cin>>n>>m>>k;
for(int i=0;i<n;++i){
  cin>>str;
  koe="";g.clear();
  for(int j=0;j<str.size();++j)koe+="0";
  for(int j=0;j<k;++j)koe[j]='1';
  while(true){
    constr(koe,str);
    //cout<<koe<<endl;
    koe=next(koe);
    if(koe=="-")break;
    }

  }

cout<<ng<<endl;
cout<<strres<<endl;
cout<<brng<<endl;

return 0;
}
/*
1 12 2
asdfg

5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
