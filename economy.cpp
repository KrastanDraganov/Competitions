#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3;
int candies[MAXN];
bool dp[MAXN][MAXN];

int calc_dp(int a, int b, int c, int n){
    dp[0][0]=true;
    for(int i=1;i<=n;++i){
        for(int sum=0;sum<b;++sum){
            dp[i][sum]=dp[i-1][sum];
            if(candies[i-1]<=sum){
                dp[i][sum] |= dp[i-1][sum-candies[i-1]];
            }
        }
    }
    for(int sum=c-a+1;sum<b;++sum){
        if(dp[n][sum]){
            return a+sum;
        }
    }
    return a+b;
}

vector<int> find_candies(int n, int sum){
    vector<int> res;
    for(int i=n-1;i>=0;--i){
        if(candies[i]<=sum and dp[i][sum-candies[i]]){
            sum-=candies[i];
            res.push_back(i);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c,n;
    cin>>a>>b>>c>>n;
    for(int i=0;i<n;++i){
        cin>>candies[i];
    }

    if(a>c){
        cout<<a<<endl<<0<<endl;
    }else if(a+b<c){
        cout<<a+b<<endl<<-1<<endl;
    }else{
        int res=calc_dp(a,b,c,n);
        cout<<res<<endl;
        if(res==a+b){
            cout<<"-1\n";
        }else{
            vector<int> needed=find_candies(n,res-a);
            cout<<(int)needed.size()<<endl;
            for(int ind : needed){
                cout<<ind+1<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}