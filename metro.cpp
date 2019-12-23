#include<iostream>
#define endl '\n'
#define MAXN 1003
using namespace std;
int height[MAXN],dp[MAXN][103],dirs[4]={-2,-1,0,1};
int price(int ind, int curr){
    int diff=curr-height[ind];
    if(height[ind]==curr){
        return 1;
    }else if(height[ind]<curr){
        return 7*diff;
    }else{
        return diff*diff;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>height[i];
    }
    for(int i=0;i<=100;++i){
        dp[0][i]=price(0,i);
    }
    for(int i=0;i<n-1;++i){
        for(int curr=1;curr<100;++curr){
            for(int add : dirs){
                int next_height=curr+add;
                if(next_height>=0 and next_height<100){
                    int curr_price=price(i+1,next_height);
                    if(dp[i+1][next_height]==0 or dp[i+1][next_height]>dp[i][curr]+curr_price){
                        dp[i+1][next_height]=dp[i][curr]+curr_price;
                    }
                }
            }
        }
    }
    int res=1e9;
    for(int i=1;i<=100;++i){
        if(dp[n-1][i]==0) continue;
        res=min(res,dp[n-1][i]);
    }
    cout<<res<<endl;
return 0;
}