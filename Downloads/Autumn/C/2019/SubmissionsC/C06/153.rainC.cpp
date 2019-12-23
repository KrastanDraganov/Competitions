#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],k,pr[1000000],sl[1000000],pr2[1000000],sl2[1000000],ans,kk,ans2,f;
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
for(int i=0;i<n;i++){
    if(s.empty()){pr[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]>=a[i]){
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
    if(s.empty()){sl[i]=-1;s.push(i);}
    else{
        while(!s.empty() and a[s.top()]>=a[i]){
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
for(int i=0;i<k;i++){
    if(pr2[p[i].first]!=-1 and sl2[p[i].first]!=-1){
        if(!(a[p[i].first]+p[i].second<=min(a[pr2[p[i].first]],a[sl2[p[i].first]]))){
            ans++;a[p[i].first]+=p[i].second;
        }
    }else if(!(pr2[p[i].first]==-1 and sl2[p[i].first]==-1)){
            ans++;a[p[i].first]+=p[i].second;
    }
}
cout<<ans<<" ";
for(int i=0;i<n;i++){
    kk=1;
    for(f=i+1;a[f]<a[i] and f<n;f++){
        kk++;
    }
    if(f!=n){
    ans2+=a[i]*kk;
    i=f-1;
    }else{
       if(i!=n-1)ans2+=a[i+1];
    }
}
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
