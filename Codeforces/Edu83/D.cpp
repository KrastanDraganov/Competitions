#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
long long MOD=998244353;
long long pascal[MAXN];

long long calc_pascal(int n, int k){
    pascal[0]=1;
    for(int i=1;i<=n;++i){
        for(int i2=min(i,k);i2>0;--i2){
            pascal[i2]=(pascal[i2]+pascal[i2-1])%MOD;
        }
    }
    return pascal[k];
}

long long fast_pow(long long num, int counter){
    if(counter==1){
        return num;
    }
    if(counter==0){
        return 1;
    }
    if(counter%2==0){
        long long curr=fast_pow(num,counter/2);
        return (curr*curr)%MOD;
    }else{
        return (num*fast_pow(num,counter-1))%MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    if(n==2){
        cout<<0<<endl;
        return 0;
    }
    long long res=n-2;
    for(long long i=m;i>m-n+1;--i){
        res*=i;
        res%=MOD;
    }
    long long divide=1;
    for(long long i=2;i<n;++i){
        divide*=i;
        divide%=MOD;
    }
    divide=fast_pow(divide,MOD-2)%MOD;
    res*=divide;
    res%=MOD;
    res*=fast_pow(2,n-3);
    res%=MOD;
    cout<<res<<endl;
return 0;
}