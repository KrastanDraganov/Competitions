#include<bits/stdc++.h>
using namespace std;
string s[10001],ss,sss;
int n,m,k,mins,ans,maxbr,ans3;
string ans2;
string nexter(string x,string y){
for(int i=0;i<max(x.size(),y.size());i++){
    if(i<min(x.size(),y.size())){
        if(x[i]>y[i])return y;
        else if(x[i]<y[i])return x;
    }else{
        if(x.size()<y.size())return x;
        else return y;
    }
}
return x;
}
bool li[10001];
int broi(string x){
int pos=0,kk=maxbr;
for(int i=0;i<n;i++){
    if(!li[i]){
        pos=0;
        for(int f=0;f<s[i].size();f++){
            if(s[i][f]==x[pos])pos++;
        }
        if(pos!=x.size())kk--;
        if(kk<ans)return 0;
    }
}
return kk;
}
void perm(string ss,int k,int last){
if(k==0){
    if(broi(sss)==ans){
        ans2=nexter(ans2,sss);
        ans3++;
    }else  if(broi(sss)>ans){
        ans2=sss;
        ans3=1;
        ans=broi(sss);
    }
}else{
    for(int i=last;i<ss.size();i++){
        sss.push_back(ss[i]);
        perm(ss,k-1,i+1);
        sss.pop_back();
    }
}
}
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m>>k;
for(int i=0;i<n;i++){
    cin>>s[i];
}
mins=1000000;
maxbr=n;
for(int i=0;i<n;i++){
    if(s[i].size()<k){
        li[i]=true;
        maxbr--;
    }else{
        if(s[i].size()<mins){
            mins=s[i].size();
            ss=s[i];
        }
    }
}
for(int i=0;i<n;i++){
    if(!li[i]){
       perm(s[i],k,0);
    }
    maxbr--;
    li[i]=true;
}
cout<<ans<<endl;
cout<<ans2<<endl;
cout<<ans3<<endl;
return 0;
}
/*
5 7 2
fagcbdaga
dcdfb
acfebdc
cfc
cegdb
*/
