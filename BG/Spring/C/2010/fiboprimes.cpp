#include<iostream>
#include<unordered_map>
#include<vector>

#define endl '\n'

using namespace std;

vector<long long> fibbonaci;
unordered_map<long long, int> dp;

bool is_prime(long long num){
    for(long long i=2;i*i<=num;++i){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int calc_res(long long num){
    if(num<2){
        return 0;
    }
    if(dp.count(num)>0){
        return dp[num];
    }
    bool check=is_prime(num);
    int counter=check;
    for(long long curr : fibbonaci){
        counter=max(counter,check+calc_res(num/curr));
    }
    return dp[num]=counter;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    fibbonaci.push_back(2ll);
    fibbonaci.push_back(3ll);
    long long curr=5;
    for(int i=3;curr<=n;++i){
        fibbonaci.push_back(curr);
        curr=fibbonaci[i-1]+fibbonaci[i-2];
    }

    cout<<calc_res(n)<<endl;
return 0;
}