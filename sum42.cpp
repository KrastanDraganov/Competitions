#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define endl '\n'
using namespace std;
long long dp[20][45][2];
vector<int> set_digits(long long num){
    vector<int> res;
    while(num){
        res.push_back(num%10);
        num/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
long long calc(int pos, int sum, bool is_smaller, vector<int> digits){
    if(pos>=digits.size()){
        return sum==42;
    }
    if(sum>42){
        return 0;
    }
    long long& ans=dp[pos][sum][is_smaller];
    if(ans!=-1){
        return ans;
    }
    int limit=is_smaller ? 9 : digits[pos];
    ans=0;
    for(int i=0;i<=limit;++i){
        ans+=calc(pos+1,sum+i,(i<digits[pos] or is_smaller),digits);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    long long res=calc(0,0,false,set_digits(r));
    memset(dp,-1,sizeof(dp));
    res-=calc(0,0,false,set_digits(l-1));
    cout<<res<<endl;
return 0;
}
/**
6661337 1234567890
6661337 123456789987654321
*/
