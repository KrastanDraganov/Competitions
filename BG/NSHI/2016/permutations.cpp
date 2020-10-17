#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3,MOD=1e9+7;
int nums[MAXN],factorial[MAXN],fenwick[MAXN];

void add_mod(int& x, int y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

int mul_mod(int x, int y){
    return (long long) x*y%MOD;
}

void update_tree(int ind, int val){
    while(ind<MAXN){
        fenwick[ind]+=val;
        ind+=(ind & (-ind));
    }
}

int sum(int ind){
    int res=0;
    while(ind>0){
        res+=fenwick[ind];
        ind-=(ind & (-ind));
    }
    return res;
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

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>nums[i];
        update_tree(nums[i], 1);
    }

    factorial[0]=1;
    for(int i=1;i<=n;++i){
        factorial[i]=mul_mod(factorial[i-1], i);
    }

    int denominator=1;
    for(int i=1;i<=n;++i){
        int curr=sum(i)-sum(i-1);
        if(curr>0){
            denominator=mul_mod(denominator, factorial[curr]);
        }
    }

    int res=1;
    for(int i=0;i<n;++i){
        int numerator=factorial[n-i-1];
        numerator=mul_mod(numerator, sum(nums[i]-1));
        
        int curr=fast_pow(denominator, MOD-2);
        numerator=mul_mod(numerator, curr);
        add_mod(res, numerator);
        
        denominator=mul_mod(denominator, fast_pow(sum(nums[i])-sum(nums[i]-1), MOD-2));
        update_tree(nums[i], -1);
    }

    cout<<res<<endl;
return 0;
}