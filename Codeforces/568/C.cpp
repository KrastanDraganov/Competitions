#include<iostream>
#define endl '\n'
#define MAXN (int)2e5+2
#define MAXM (int)2e7+2
using namespace std;
int n,m,exam_time[MAXN],dp[10005][105];
bool used[10005][105];
int check(int sum, int ind, int cons_ind){
    if(cons_ind==3) cout<<sum<<" "<<ind<<" "<<dp[sum][ind]<<" "<<boolalpha<<used[sum][ind]<<endl;
    if(used[sum][ind]) return dp[sum][ind];
    used[sum][ind]=true;
    if(sum<=m) return dp[sum][ind]=0;
    if(ind>=cons_ind) return 10000000;
    return dp[sum][ind]=min(check(sum-exam_time[ind],ind+1,cons_ind)+1,check(sum,ind+1,cons_ind));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int curr=0;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>exam_time[i];
        if(curr+exam_time[i]<=m){
            cout<<"0 \n";
            curr+=exam_time[i];
            continue;
        }
        curr+=exam_time[i];
        cout<<check(curr,0,i)<<" \n";
    }
    cout<<endl;
return 0;
}