#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int nums[MAXN];
bool dp[3*MAXN*MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int negative=0,positive=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        if(nums[i]>0){
            positive+=nums[i];
        }else{
            negative+=nums[i];
        }
    }
    
    negative=-negative;
    dp[negative+nums[0]]=true;
    
    int res=1;
    for(int i=1;i<n;++i){
        if(nums[i]<0){
            for(int i2=nums[i]-negative;i2<=negative+positive;++i2){
                if(dp[negative+i2-nums[i]] and !dp[negative+i2]){
                    ++res;
                    dp[negative+i2]=true;
                }
            }
        }else if(nums[i]>0){
            for(int i2=negative+positive;i2>=nums[i]-negative;--i2){
                if(dp[negative+i2-nums[i]] and !dp[negative+i2]){
                    ++res;
                    dp[negative+i2]=true;
                }
            }
        }
        if(!dp[negative+nums[i]]){
            ++res;
            dp[negative+nums[i]]=true;
        }
    }
    cout<<res<<endl;
return 0;
}