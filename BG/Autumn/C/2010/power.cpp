#include<iostream>

#define endl '\n'

using namespace std;

long long power(long long num, long long factor, long long mod){
    if(factor==1){ 
        return num%mod;
    }
    if(factor%2==0){
        long long mid=power(num,factor/2,mod)%mod;
        return (mid*mid)%mod;
    }
    return (num*(power(num,factor-1,mod)%mod))%mod;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long mod;
    cin>>n>>mod;
    
    long long res=0;
    for(int i=0;i<n;++i){
        long long curr;
        cin>>curr;
        res=(res+power(curr,i+2,mod))%mod;
    }
    cout<<res<<endl;
return 0;
}