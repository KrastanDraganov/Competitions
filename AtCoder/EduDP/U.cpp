#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=16;
long long points[MAXN][MAXN],dp[(1<<MAXN)+3],total[(1<<MAXN)+3];

void calc_dp(int mask, int curr, int ind, const vector<int>& missing){
    if(ind==(int)missing.size()){
        int new_mask=(mask | curr);
        dp[new_mask]=max(dp[new_mask],dp[mask]+total[curr]);
        return;
    }
    calc_dp(mask,curr,ind+1,missing);
    calc_dp(mask,(curr | (1<<missing[ind])),ind+1,missing);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>points[i][i2];
        }
    }

    for(int mask=0;mask<(1<<n);++mask){
        for(int i=0;i<n;++i){
            for(int i2=i+1;i2<n;++i2){
                if((mask & (1<<i)) and (mask & (1<<i2))){
                    total[mask]+=points[i][i2];
                }
            }
        }
    }

    for(int mask=0;mask<(1<<n);++mask){
        vector<int> missing;
        for(int i=0;i<n;++i){
            if(!(mask & (1<<i))){
                missing.push_back(i);
            }
        }
        calc_dp(mask,0,0,missing);
    }

    cout<<dp[(1<<n)-1]<<endl;
return 0;
}