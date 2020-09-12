#include<iostream>

#define endl '\n'

using namespace std;

const int MOD=1e9+7;

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

    int curr=fast_pow(num,degree/2);
    return mul_mod(curr, curr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    cout<<fast_pow(2,n)<<endl;
return 0;
}