#include<iostream>
#include<vector>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=3e5+3;
long long soldiers[MAXN];
int dp[3][MAXN];

int mex(vector<int> nums){
    for(int i=0;i<nums.size();++i){
        bool check=false;
        for(int i2=0;i2<nums.size();++i2){
            if(i==nums[i2]){
                check=true;
                break;
            }
        }
        if(!check){
            return i;
        }
    }
    return nums.size();
}

int value(int ind, long long num, int cycle){
    if(num>200){
        return dp[ind][(num-200)%cycle+200];
    }
    return dp[ind][num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        int cycle=-1;
        memset(dp,0,sizeof(dp));
        for(int i=1;cycle==-1;++i){
            dp[0][i]=mex({dp[0][max(i-x,0)],dp[1][max(i-y,0)],dp[2][max(i-z,0)]});
            dp[1][i]=mex({dp[0][max(i-x,0)],dp[2][max(i-z,0)]});
            dp[2][i]=mex({dp[0][max(i-x,0)],dp[1][max(i-y,0)]});
            bool check=(i>200);
            for(int i2=0;i2<5;++i2){
                check &= (dp[0][i-i2]==dp[0][200-i2] and dp[1][i-i2]==dp[1][200-i2] and dp[2][i-i2]==dp[2][200-i2]);
            }
            if(check){
                cycle=i;
            }
        }
        cycle-=200;
        int grundy=0;
        for(int i=0;i<n;++i){
            cin>>soldiers[i];
            grundy^=value(0,soldiers[i],cycle);
        }
        int res=0;
        for(int i=0;i<n;++i){
            grundy^=value(0,soldiers[i],cycle);
            if((grundy^value(0,max(soldiers[i]-x,0ll),cycle))==0){
                ++res;
            }
            if((grundy^value(1,max(soldiers[i]-y,0ll),cycle))==0){
                ++res;
            }
            if((grundy^value(2,max(soldiers[i]-z,0ll),cycle))==0){
                ++res;
            }
            grundy^=value(0,soldiers[i],cycle);
        }
        cout<<res<<endl;
    }
return 0;
}