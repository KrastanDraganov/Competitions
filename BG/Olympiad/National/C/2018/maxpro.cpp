#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=203;
long long dp[MAXN][MAXN];

long long sol(long long sum,int number){
    if(sum==0){ 
        return 1;
    }
    if(sum<0 or number==0){ 
        return 0;
    }

    long long& res=dp[sum][number];
    if(res!=0){ 
        return res;
    }

    res=max(sol(sum,number-1),sol(sum-number,number-1)*number);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    cout<<sol(n,n)<<endl;
return 0;
}