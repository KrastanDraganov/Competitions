#include<iostream>
#include<algorithm>
#include<utility>

#define endl '\n'

using namespace std;

const int MAXN=2e3+3;
pair<int,int> prices[2][MAXN];
int prefix[2][MAXN],dp[MAXN][MAXN];

void calc_prices(int ind, int n){
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        prices[ind][i]={curr,i+1};
    }
    for(int i=1;i<=n;++i){
        prefix[ind][i]=prefix[ind][i-1]+prices[ind][i-1].first;
    }
    sort(prices[ind],prices[ind]+n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<2;++i){
        calc_prices(i,(i ? m : n));
    }

    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            dp[i][i2]=1;
        }
    }
    int l=0,r=0;
    while(l<n and r<m){
        if(prices[0][l].first<prices[1][r].first){
            ++l;
        }else if(prices[0][l].first>prices[1][r].first){
            ++r;
        }else{
            dp[prices[0][l].second][prices[1][r].second]=0;
            ++l;
            ++r;
        }
    }

    int max_side=0,max_sum=0,res_l[2]={0},res_r[2]={0};
    for(int i=1;i<=n;++i){
        for(int i2=1;i2<=m;++i2){
            if(dp[i][i2]==1){
                dp[i][i2]=min({dp[i-1][i2],dp[i][i2-1],dp[i-1][i2-1]})+1;
                int curr_l[2]={i-dp[i][i2]+1,i2-dp[i][i2]+1},curr_r[2]={i,i2};
                int curr_sum=0;
                for(int i=0;i<2;++i){
                    curr_sum+=prefix[i][curr_r[i]]-prefix[i][curr_l[i]-1];
                }
                if(dp[i][i2]>max_side or (dp[i][i2]==max_side and curr_sum>max_sum)){
                    max_side=dp[i][i2];
                    max_sum=curr_sum;
                    for(int i=0;i<2;++i){
                        res_l[i]=curr_l[i];
                        res_r[i]=curr_r[i];
                    }
                }
            }
        }
    }

    if(max_sum==0){
        cout<<"0\n";
    }else{
        cout<<max_sum<<endl;
        for(int i=0;i<2;++i){
            cout<<res_l[i]<<" "<<res_r[i]<<endl;
        }
    }
return 0;
}