#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=1e3+3,BASE=1e9;

struct Long {
    
    int len,digits[64];
    
    Long(){
        len=1;
        for(int i=0;i<64;++i){
            digits[i]=0;
        }
    }
    
    Long(long long num){
        len=(num<1);
        for(int i=0;i<64;++i){
            digits[i]=0;
        }
        while(num){
            digits[len++]=num%BASE;
            num/=BASE;
        }
    }
    
    Long(const Long& num){
        len=num.len;
        for(int i=0;i<64;++i){
            digits[i]=num.digits[i];
        }
    }
    
    void operator+=(const Long& num){
        len=max(len,num.len);
        int carry=0;
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
    
    void print(){
        fprintf(stdout,"%d",digits[len-1]);
        for(int i=len-2;i>=0;--i){
            fprintf(stdout,"%09d",digits[i]);
        }
        fprintf(stdout,"\n");
    }
} dp[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    Long curr(1ll);
    for(int i=2;i<n;++i){
        dp[i]+=dp[i-2];
        dp[i]+=curr;
        curr+=curr;
    }
    dp[n-1].print();
return 0;
}