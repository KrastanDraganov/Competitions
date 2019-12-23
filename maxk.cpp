#include<iostream>
#define endl '\n'
#define MAXN 1003
using namespace std;
int sum[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    sum[0]=0;
    int ans=(-1e9);
    for(int i=1;i<=n;++i){
        int num;
        cin>>num;
        sum[i]=sum[i-1]+num;
        if(i>=k){
            ans=max(ans,sum[i]-sum[i-k]);
        }
    }
    cout<<ans<<endl;
return 0;
}