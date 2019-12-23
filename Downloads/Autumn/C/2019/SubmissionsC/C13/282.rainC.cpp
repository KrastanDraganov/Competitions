#include<bits/stdc++.h>
using namespace std;
int a[1000005];
pair<int,int> k[1000005];
stack<int> s;
int n,m;
int v(){
    for(int i=0;i<n;i++){
        while(s.size()>=2 && a[s.top()]<a[i]) s.pop();
        s.push(i);
    }
    int x=s.top(),y,v=0;
    s.pop();
    while(!s.empty()){
        y=s.top();
        s.pop();
        v+=(max(x,y)-min(x,y))*min(a[x],a[y]);
        //cout<<x<<" "<<y<<" "<<v<<endl;
        x=y;
    }
    return v;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,y,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        a[x]+=y;
        k[i]={x,y};
        ans++;
    }
    int V=v();
    for(int i=0;i<m;i++){
        x=k[i].first;
        y=k[i].second;
        a[x]-=y;
        if(v()!=V){
            a[x]+=y;
        }
        else ans--;
    }
    cout<<ans<<" "<<v()<<endl;
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
