#include<iostream>

#define endl '\n'
using namespace std;

const int MAXN=20;
bool lights[MAXN][MAXN];
int dp[MAXN][MAXN];

int set_val_row(int row, int col){
    if((lights[row][col] and dp[row-1][col]%2==1) or (!lights[row][col] and dp[row-1][col]%2==0)){
        return dp[row-1][col]+1;
    }
    return dp[row-1][col]+2;
}

int set_val_col(int row, int col){
    if((lights[row][col] and dp[row][col-1]%2==1) or (!lights[row][col] and dp[row][col-1]%2==0)){
        return dp[row][col-1]+1;
    }
    return dp[row][col-1]+2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<n;++i2){
            cin>>lights[i][i2];
        }
    }
    
    dp[0][0]=1;
    for(int i=1;i<n;++i){
        dp[i][0]=set_val_row(i,0);
        dp[0][i]=set_val_col(0,i);
    }
    
    for(int i=1;i<n;++i){
        for(int i2=1;i2<n;++i2){
            int left_val=set_val_col(i,i2),up_val=set_val_row(i,i2);
            dp[i][i2]=min(left_val,up_val);
        }
    }
    cout<<dp[n-1][n-1]<<endl;
return 0;
}