#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+9;
int n, k, a[MAXN], b[MAXN], p[MAXN], s[MAXN];
int ans[MAXN];

int cost=0;
int water=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int index, h;
        cin>>index>>h;
        b[index]+=h;
    }
    p[0]=b[0];
    s[n-1]=b[n-1];
    for(int i=1;i<n;i++){
        p[i]=max(b[i], p[i-1]);
        int j=(n-1)-i;
        s[j]=max(b[j], s[j+1]);
    }
    for(int i=0;i<n;i++){
        int l=(i==0?0:p[i-1]);
        int r=(i==n-1?0:s[i+1]);
        if(b[i]>l||b[i]>r){
            ans[i]=max(a[i], min(b[i], max(l, r)));
            cost+=ans[i]-a[i];
        }else{
            //cout<<'.';
            ans[i]=a[i];
        }
    }
    int h=ans[0], w=0, f=0;
    for(int i=1;i<n;i++){
        w++;
        if(ans[i]>=h){
            water+=w*h;
            h=ans[i];
            w=0;
            f=0;
        }else{
            f+=ans[i];
        }
    }
    water+=f;
    cout<<cost<<' '<<water<<'\n';
}
/*
6
2 4 2 4 2 1
2
2 1
4 1
*/
