#include<iostream>
#define endl '\n'
using namespace std;
long long MOD=1e9+7;
long long power(long long num, long long counter){
    if(counter==1){
        return num;
    }
    if(counter%2){
        return (num*power(num,counter-1))%MOD;
    }else{
        long long curr=power(num,counter/2)%MOD;
        return (curr*curr)%MOD;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin>>n>>k;
    long long numerator=1,denominator=1;
    for(long long i=n-1;i>n-k;--i){
        numerator*=i;
        numerator%=MOD;
    }
    for(long long i=2;i<k;++i){
        denominator*=i;
        denominator%=MOD;
    }
    denominator=power(denominator,MOD-2);
    numerator*=denominator;
    numerator%=MOD;
    cout<<numerator<<endl;
return 0;
}