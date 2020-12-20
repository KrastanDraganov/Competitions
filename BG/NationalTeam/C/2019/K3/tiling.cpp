#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103,MAXM=(1<<10)+3,MOD=1e9+7;
int dp[MAXN][MAXM];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

bool is_set(int pos, int mask){
    return (1<<pos) & mask;
}

// Mask values: 0 - empty cell, will be filled with horizontal domino
// 1 - occupied cell with either vertical or horizontal domino
bool check(int prev_col, int curr_col, int n){
    int counter=0;
    
    for(int i=0;i<n;++i){
        if(is_set(i, prev_col) and is_set(i, curr_col)){
            ++counter;
            continue;
        }

        if(counter & 1){
            return false;
        }
        if(!is_set(i, prev_col) and !is_set(i, curr_col)){
            return false;
        }

        counter=0;
    }
    
    return counter%2==0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    
    if(n>m){
        swap(n,m);
    }
    
    int limit=(1<<n);
    dp[0][limit-1]=1;
    for(int i=1;i<=m;++i){
        for(int curr_col=0;curr_col<limit;++curr_col){
            for(int prev_col=0;prev_col<limit;++prev_col){
                if(check(prev_col, curr_col, n)){
                    add_mod(dp[i][curr_col], dp[i-1][prev_col]);
                }
            }
        }
    }

    cout<<dp[m][limit-1]<<endl;
return 0;
}