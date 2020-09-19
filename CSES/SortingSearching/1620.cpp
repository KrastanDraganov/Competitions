#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int machines[MAXN];

bool check(long long time, int n, int t){
    long long tasks=0;

    for(int i=0;i<n;++i){
        tasks+=(time/machines[i]);
    }

    return tasks>=t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t;
    cin>>n>>t;
    
    int min_time=1e9+3;
    for(int i=0;i<n;++i){
        cin>>machines[i];
        min_time=min(min_time, machines[i]);
    }

    long long l=0,r=(long long)t*min_time;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid,n,t)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    cout<<l<<endl;
return 0;
}