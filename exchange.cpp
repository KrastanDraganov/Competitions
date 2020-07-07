#include<iostream>
#include<cstring>

#define endl '\n'

using namespace std;

const int MAXN=203,MAXS=2e3+3,BASE=1e9;

struct Long {
    int len,digits[53];
    
    Long(){
        len=1;
        for(int i=0;i<53;++i){
            digits[i]=0;
        }
    }
    
    Long(long long num){
        len=(num<1);
        for(int i=0;i<53;++i){
            digits[i]=0;
        }
        while(num){
            digits[len++]=num%BASE;
            num/=BASE;
        }
    }
    
    Long(const Long& num){
        len=num.len;
        for(int i=0;i<53;++i){
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
} dp[MAXN][MAXS];
bool already[MAXN];
int value[MAXN],counter[MAXN],value_ind[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int s,n;
    cin>>s>>n;
    for(int i=0;i<n;++i){
        cin>>value[i];
    }
    for(int i=0;i<n;++i){
        cin>>counter[i];
        if(already[value[i]]){
            counter[value_ind[value[i]]]+=counter[i];
            counter[i]=0;
        }else{
            already[value[i]]=true;
            value_ind[value[i]]=i;
        }
    }
    
    dp[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int sum=0;sum<=s;++sum){
            dp[i][sum]=dp[i-1][sum];
            for(int i2=1;i2<=counter[i-1] and value[i-1]*i2<=sum;++i2){
                dp[i][sum]+=dp[i-1][sum-i2*value[i-1]];
            }
        }
    }
    dp[n][s].print();
return 0;
}