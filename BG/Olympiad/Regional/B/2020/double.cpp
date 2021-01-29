#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=203,INF=1e9;
int weights[MAXN],dp[2][MAXN][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,limit1,limit2;
    cin>>n>>limit1>>limit2;

    for(int i=0;i<n;++i){
        cin>>weights[i];
    }

    for(int bag1=0;bag1<=limit1;++bag1){
        for(int bag2=0;bag2<=limit2;++bag2){
            dp[0][bag1][bag2]=-INF;
        }
    }
    dp[0][0][0]=0;

    for(int i=1;i<=n;++i){
        int curr=(i & 1);
        int prev=(curr ^ 1);

        for(int bag1=0;bag1<=limit1;++bag1){
            for(int bag2=0;bag2<=limit2;++bag2){
                dp[curr][bag1][bag2]=dp[prev][bag1][bag2];
                
                if(bag1>=weights[i-1]){
                    dp[curr][bag1][bag2]=max(dp[curr][bag1][bag2], dp[prev][bag1-weights[i-1]][bag2]+weights[i-1]);
                }

                if(bag2>=weights[i-1]){
                    dp[curr][bag1][bag2]=max(dp[curr][bag1][bag2], dp[prev][bag1][bag2-weights[i-1]]+weights[i-1]);
                }
            }
        }
    }

    int res=0;
    for(int bag1=0;bag1<=limit1;++bag1){
        for(int bag2=0;bag2<=limit2;++bag2){
            res=max(res, dp[n & 1][bag1][bag2]);
        }
    }

    cout<<res<<endl;
return 0;
}