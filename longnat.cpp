#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e4+3;
int nums[MAXN],dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int curr=-1,n=0;
    for(int i=0;cin>>curr;i++){
        nums[i]=curr;
        n++;
    }
    
    dp[0]=1;
    for(int i=1;i<n;i++){
        int counter=0;
        for(int i2=0;i2<i;i2++){
            if(nums[i2]==nums[i]-1){
                counter=max(dp[i2],counter);
            }
        }
        dp[i]=counter+1;
    }

    int res=-1;
    for(int i=0;i<n;i++){
        res=max(dp[i],res);
    }
    cout<<res<<endl;
return 0;
}