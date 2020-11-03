#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=73;
int nums[MAXN][MAXN];
// dp[x][y][counter][rem] - maximum sum of #counter(<=m/2) elements
// on col #y, row #x, that have remainder #rem
int dp[MAXN][MAXN][MAXN][MAXN];
int prev_row_max[MAXN];

void self_max(int& x, int y){
    x=max(x, y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>nums[i][i2];
        }
    }

    int limit=m/2;
    for(int x=0;x<=n;++x){
        for(int y=0;y<=m;++y){
            for(int counter=0;counter<=limit;++counter){
                for(int rem=0;rem<k;++rem){
                    dp[x][y][counter][rem]=-1e9;
                }
            }
        }
    }

    dp[0][0][0][0]=0;
    for(int x=0;x<n;++x){
        for(int y=0;y<m;++y){
            for(int counter=0;counter<=min(y+1, limit);++counter){
                for(int rem=0;rem<k;++rem){
                    int nextx=(y==m-1 ? x+1 : x);
                    int nexty=(y==m-1 ? 0 : y+1);
                    
                    if(x==nextx){
                        self_max(dp[nextx][nexty][counter][rem], dp[x][y][counter][rem]);
                    }else{
                        self_max(dp[nextx][nexty][0][rem], dp[x][y][counter][rem]);
                    }

                    if(counter==limit){
                        continue;
                    }

                    int next_rem=(rem+nums[x][y])%k;
                    int new_sum=dp[x][y][counter][rem]+nums[x][y];
                    if(x==nextx){
                        self_max(dp[nextx][nexty][counter+1][next_rem], new_sum);
                    }else{
                        self_max(dp[nextx][nexty][0][next_rem], new_sum);
                    }
                }
            }
        }
    }
    
    self_max(dp[n][0][0][0], 0);
    cout<<dp[n][0][0][0]<<endl;
return 0;
}