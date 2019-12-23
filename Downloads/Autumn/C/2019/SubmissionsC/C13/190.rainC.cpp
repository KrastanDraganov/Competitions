#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool b[1000005];
int c[1000005];
int k[1000005];
stack<int> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
    }
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
    x=s.top();
    s.pop();
    while(!s.empty()){
        y=s.top();
        s.pop();
        v+=(x-y)*min(a[x],a[y]);
        x=y;
    }
    cout<<ans<<" "<<v<<endl;
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
