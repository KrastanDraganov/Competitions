#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+6, MAXK=1e3+69;

int n, k;
int a[MAXN], p[MAXN], s[MAXN];
int step[MAXK];
bool usedp[MAXN], useds[MAXN];


void findP(){
    priority_queue<pair<int, int> > q;
    q.push({0, 0});
    while(!q.empty()){
        int ci=-q.top().first;
        int cv=q.top().second;
        q.pop();
        if(ci>=n)continue;
        if(usedp[ci])continue;
        usedp[ci]=true;
        p[ci]=a[ci]+cv;
        for(int i=0;i<k;i++){
            q.push({-(ci+step[i]), p[ci]});
        }
    }
    for(int i=1;i<n;i++){
        p[i]=max(p[i-1], p[i]);
        //cerr<<p[i]<<' ';
    }
}

void findS(){
    priority_queue<pair<int, int> > q;
    q.push({n-1, 0});
    while(!q.empty()){
        int ci=q.top().first;
        int cv=q.top().second;
        q.pop();
        if(ci<0)continue;
        if(useds[ci])continue;
        useds[ci]=true;
        s[ci]=a[ci]+cv;
        for(int i=0;i<k;i++){
            q.push({ci-step[i], s[ci]});
        }
    }
    for(int i=n-2;i>=0;i--){
        s[i]=max(s[i+1], s[i]);
        //cerr<<s[i]<<' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<k;i++)cin>>step[i];
    findP();
    //cerr<<'\n';
    findS();
    //cerr<<'\n';
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans=max(ans, p[i]+s[i+1]);
        //cerr<<p[i]<<' '<<s[i+1]<<'\n';
    }
    cout<<ans;
}
/*
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
*/
