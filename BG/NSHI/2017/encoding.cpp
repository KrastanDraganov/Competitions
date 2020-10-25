#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
const long long MOD=(long long)(1e18)+3;
int nums[MAXN],fenwick[MAXN];
long long factorial[MAXN];

void add_mod(long long& x, long long y){
    x+=y;
    if(x>=MOD){
        x-=MOD;
    }
}

long long mul_mod(long long x, long long y){
    long long res=0;
    while(y>0){
        if(y & 1){
            add_mod(res, x);
            --y;
        }else{
            add_mod(x, x);
            y/=2;
        }
    }
    return res;
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

long long fast_pow(long long num, long long degree){
    long long res=1;
    while(degree>0){
        if(degree & 1){
            res=mul_mod(res, num);
            --degree;
        }else{
            num=mul_mod(num, num);
            degree/=2;
        }
    }
    return res;
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

    long long denominator=1;
    for(int i=1;i<=n;++i){
        int curr=sum(i)-sum(i-1);
        if(curr>0){
            denominator=mul_mod(denominator, factorial[curr]);
        }
    }
    denominator=fast_pow(denominator, MOD-2);

    long long res=0;
    for(int i=0;i<n;++i){
        long long numerator=factorial[n-i-1];
        numerator=mul_mod(numerator, sum(nums[i]-1));
        
        numerator=mul_mod(numerator, denominator);
        add_mod(res, numerator);
        
        denominator=mul_mod(denominator, sum(nums[i])-sum(nums[i]-1));
        update_tree(nums[i], -1);
    }

    cout<<res<<endl;
return 0;
}