#include<iostream>
#define endl '\n'
#define MAXN 19
#define MAXM 1459 //18*81+1
using namespace std;
long long dp[MAXN][MAXM],sum[MAXM];
int is_first[MAXM];
int digits_sum(long long x){
    int res=0;
    while(x!=0){
        res+=(x%10)*(x%10);
        x/=10;
    }
    return res;
}
bool check(long long x){
    if(is_first[x]==0){
        is_first[x]=-1;
        if(check(digits_sum(x))){
            is_first[x]=1;
        }
    }
    return is_first[x]==1;
}
long long sol(long long x){
    for(int i=0;i<MAXM;++i){
        sum[i]=0;
    }
    sum[digits_sum(x)]=1;
    int counter=0;
    while(x!=0){
        int d=x%10;
        x/=10;
        int sumx=digits_sum(x);
        for(int i=0;i<d;++i){
            for(int i2=0;i2<MAXM-sumx-i*i;++i2){
                sum[i2+sumx+i*i]+=dp[counter][i2];
            }
        }
        ++counter;
    }
    long long res=0;
    for(int i=0;i<MAXM;++i){
        if(check(i)){
            res+=sum[i];
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    is_first[0]=-1;
    is_first[1]=1;
    for(int i=0;i<MAXM;++i){
       check(i); 
    }
    dp[0][0]=1;
    for(int i=1;i<MAXN;++i){
        for(int i2=0;i2<10;++i2){
            for(int i3=0;i3<MAXM-i2*i2;++i3){
                dp[i][i3+i2*i2]+=dp[i-1][i3];
            }
        }
    }
    long long a,b;
    cin>>a>>b;
    cout<<sol(b)-sol(a-1)<<endl;
return 0;
}