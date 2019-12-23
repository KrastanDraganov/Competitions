#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],k,pr[1000000],sl[1000000],pr2[1000000],sl2[1000000],ans,kk,ans2,f,lasts;
pair<int,int> p[1000000];
stack<int> s;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
cin>>k;
for(int i=0;i<k;i++){
    cin>>p[i].first>>p[i].second;
}
for(int i=0;i<k;i++){
    a[p[i].first]+=p[i].second;
}
while(!s.empty())s.pop();
for(int i=0;i<n;i++){
    if(s.empty()){pr2[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]<=a[i]){
            s.pop();
        }
        if(!s.empty()){
            pr2[i]=s.top();
        }else{
            pr2[i]=-1;
        }
        s.push(i);
    }
}
while(!s.empty())s.pop();
for(int i=n-1;i>=0;i--){
    if(s.empty()){sl2[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]<=a[i]){
            s.pop();
        }
        if(!s.empty()){
            sl2[i]=s.top();
        }else{
            sl2[i]=-1;
        }
        s.push(i);
    }
}

while(!s.empty())s.pop();
for(int i=0;i<n;i++){
    if(s.empty()){pr[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]<a[i]){
            s.pop();
        }
        if(!s.empty()){
            pr[i]=s.top();
        }else{
            pr[i]=-1;
        }
        s.push(i);
    }
}
while(!s.empty())s.pop();
for(int i=n-1;i>=0;i--){
    if(s.empty()){sl[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]<a[i]){
            s.pop();
        }
        if(!s.empty()){
            sl[i]=s.top();
        }else{
            sl[i]=-1;
        }
        s.push(i);
    }
}


ans=k;
for(int i=0;i<k;i++){
    if((pr[p[i].first]==-1 and sl[p[i].first]==-1) or (pr[p[i].first]!=-1 and sl[p[i].first]!=-1)){
        a[p[i].first]-=p[i].second;ans--;
    }
}
cout<<ans<<" ";
int pos=0;
int ff,ss;
while(true){
    if(sl2[pos]!=-1){
    ans2+=a[pos]*(sl2[pos]-pos);
    pos=sl2[pos];
    }else{
       ff=pos;
       break;
    }
}
pos=n-1;
while(true){
    if(pr2[pos]!=-1){
    ans2+=a[pos]*(pos-pr2[pos]);
    pos=pr2[pos];
    }else{
       ss=pos;
       break;
    }
}
ans2+=(ss-ff)*a[ss];
cout<<ans2<<endl;
return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
/*
8
2 3 1 2 1 3 4 1
3
1 1
5 1
6 1
*/

