#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=503,BASE=1e9,MAXD=150;

struct Long {
    int len;
    long long digits[MAXD];
    
    Long(){
        len=1;
        for(int i=0;i<MAXD;++i){
            digits[i]=0;
        }
    }
    
    Long(long long num){
        len=(num<1);
        for(int i=0;i<MAXD;++i){
            digits[i]=0;
        }
        while(num){
            digits[len++]=num%BASE;
            num/=BASE;
        }
    }
    
    Long(const Long& num){
        len=num.len;
        for(int i=0;i<MAXD;++i){
            digits[i]=num.digits[i];
        }
    }
    
    void operator+=(const Long& num){
        len=max(len,num.len);
        long long carry=0;
        for(int i=0;i<len;++i){
            carry+=digits[i]+num.digits[i];
            digits[i]=carry;
            if(carry>=BASE){
                digits[i]-=BASE;
                carry=1;
            }else{
                carry=0;
            }
        }
        if(carry){
            digits[len++]=carry;
        }
    }

    void operator*=(int num){
        long long carry=0;
        for(int i=0;i<len;++i){
            carry+=(long long)num*digits[i];
            digits[i]=carry;
            if(carry>=BASE){
                digits[i]%=BASE;
            }
            carry/=BASE;
        }
        if(carry){
            digits[len++]=carry;
        }
    }
    
    void print(){
        fprintf(stdout,"%lld",digits[len-1]);
        for(int i=len-2;i>=0;--i){
            fprintf(stdout,"%09lld",digits[i]);
        }
        fprintf(stdout,"\n");
    }
} dp[2][MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,p;
    cin>>n>>p;

    dp[0][0]=2;
    dp[1][0]=n-2;
    for(int i=1;i<p;++i){
        dp[0][i]=dp[0][i-1];
        Long curr=dp[1][i-1];
        curr*=2;
        dp[0][i]+=curr;
        dp[1][i]=dp[0][i-1];
        dp[1][i]*=(n-2);
        curr=dp[1][i-1];
        curr*=(n-2);
        dp[1][i]+=curr;
    }

    dp[0][p-1]+=dp[1][p-1];
    dp[0][p-1].print();
return 0;
}