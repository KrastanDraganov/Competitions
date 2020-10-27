// Number of different sums of k numbers equal to n
// Solved with combinations with repetition
// 1 1 1 1 ... 1 - we need to put k-1 pivots between two ones
// Sum of the ones between two pivots are the k numbers

#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e6+3,MOD=1e9+7;
int factorial[2*MAXN];

int mul_mod(int x, int y){
    return (long long) x*y%MOD;
}

int fast_pow(int num, int degree){
    if(degree==1){
        return num;
    }

    if(degree & 1){
        return mul_mod(num, fast_pow(num, degree-1));
    }

    int half=fast_pow(num, degree/2);
    return mul_mod(half, half);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;

    factorial[0]=1;
    for(int i=1;i<=n+k;++i){
        factorial[i]=mul_mod(factorial[i-1], i);
    }

    int res=factorial[n+k-1];
    res=mul_mod(res, fast_pow(factorial[k-1], MOD-2));
    res=mul_mod(res, fast_pow(factorial[n], MOD-2));

    cout<<res<<endl;
return 0;
}