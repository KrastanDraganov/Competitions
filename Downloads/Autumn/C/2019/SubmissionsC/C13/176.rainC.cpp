#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool b[1000005];
int c[1000005];
int k[1000005];
stack<int> s;
int n,m,x,y;
pair<int,int> r1(){
    for(int i=0;i<n;i++){
        x=i-1;
        while(x!=-1 && a[x]<a[i]){
            x=c[x];
        }
        c[i]=x;
        b[i]=true;
        if(x!=-1){
            while(!s.empty() && s.top()!=x){
                b[s.top()]=false;
                s.pop();
            }
        }
        s.push(i);
    }
    int ans=0,v=0;
    for(int i=0;i<m;i++){
        if(b[k[i]])ans++;
    }
    x=s.top();
    s.pop();
    while(!s.empty()){
        y=s.top();
        s.pop();
        v+=(x-y)*min(a[x],a[y]);
        x=y;
    }
    return {ans,v};
}
pair<int,int> r2(){
    for(int i=n-1;i>=0;i--){
        x=i+1;
        while(x!=n && a[x]<a[i]){
            x=c[x];
        }
        c[i]=x;
        b[i]=true;
        if(x!=n){
            while(!s.empty() && s.top()!=x){
                b[s.top()]=false;
                s.pop();
            }
        }
        s.push(i);
    }
    int ans=0,v=0;
    for(int i=0;i<m;i++){
        if(b[k[i]])ans++;
    }
    x=s.top();
    s.pop();
    while(!s.empty()){
        y=s.top();
        s.pop();
        v+=(y-x)*min(a[x],a[y]);
        x=y;
    }
    return {ans,v};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        a[x]+=y;
        k[i]=x;
    }
    int ans1,v1;
    int ans2,v2;
    pair<int,int> sol=r1();
    ans1=sol.first;
    v1=sol.second;
    sol=r2();
    ans2=sol.first;
    v2=sol.second;
    if(v1>v2){
        cout<<ans1<<" "<<v1<<endl;
    }else{
        cout<<ans2<<" "<<v2<<endl;
    }
    return 0;
}
/*
6
2 4 2 4 2 1
2
2 1
4 1

6
2 4 2 4 2 1
4
0 3
2 1
4 1
5 5
*/
