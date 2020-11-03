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
    for(int x=1;x<=n;++x){
        for(int rem=0;rem<k;++rem){
            prev_row_max[rem]=0;
            for(int counter=0;counter<=limit;++counter){
                self_max(prev_row_max[rem], dp[x-1][m][counter][rem]);
            }
        }

        for(int y=1;y<=m;++y){
            for(int rem=0;rem<k;++rem){
                dp[x][y][0][rem]=prev_row_max[rem];
                for(int counter=1;counter<=min(y+1, limit);++counter){
                    dp[x][y][counter][rem]=dp[x][y-1][counter][rem];

                    int prev_rem=(rem-nums[x-1][y-1]+k)%k;
                    self_max(dp[x][y][counter][rem], nums[x-1][y-1]+dp[x][y-1][counter-1][prev_rem]);
                }
            }
        }
    }
    
    int res=0;
    for(int counter=0;counter<=limit;++counter){
        self_max(res, dp[n][m][counter][0]);
    }

    cout<<res<<endl;
return 0;
}