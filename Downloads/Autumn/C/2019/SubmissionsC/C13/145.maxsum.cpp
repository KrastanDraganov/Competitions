#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int k[1005];
int d1[100005];
int d2[100005];
int p[100005];
int f1(int x){
    if(x==0)return a[0];
    int ans=-10000000;
    bool b=true;
    for(int i=0;i<m;i++){
        if(x-k[i]>=0 && d1[x-k[i]]!=-10000000){
            ans=max(ans,d1[x-k[i]]);
            b=false;
        }
    }
    if(b){
        return -10000000;
    }
    return a[x]+ans;
}
int f2(int x){
    if(x==n-1)return a[n-1];
    int ans=-10000000;
    bool b=true;
    for(int i=0;i<m;i++){
        if(x+k[i]<n && d2[x+k[i]]!=-10000000){
            ans=max(ans,d2[x+k[i]]);
            b=false;
        }
    }
    if(b){
        return -10000000;
    }
    return a[x]+ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>k[i];
    }
    for(int i=0;i<n;i++){
        d1[i]=f1(i);
        //cout<<d1[i]<<" ";
        p[i]=max(p[i-1],d1[i]);
    }
    //cout<<endl;
    int ans=-10000000;
    for(int i=n-1;i>=0;i--){
        d2[i]=f2(i);
        ans=max(ans,d2[i]+p[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
-1 -1 -1 4 -1 -1
3 2
*/
