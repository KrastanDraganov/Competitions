#include<iostream>
#include<cstring>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXM=12,BASE=1e9;
struct Long {
    int len,digits[16];
    
    Long(){
        len=1;
        memset(digits,0,sizeof(digits));
    }
    
    Long(long long num){
        len=(num<1);
        memset(digits,0,sizeof(digits));
        while(num){
            digits[len++]=num%BASE;
            num/=BASE;
        }
    }
    
    Long(const Long& num){
        len=num.len;
        for(int i=0;i<16;++i){
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
} dp[MAXM];
int wanted[MAXM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>wanted[i];
    }
    
    dp[0]=1;
    for(int i=1;i<=n;++i){
        int dub=i;
        string s="";
        while(dub){
            s+=(dub%10)+'0';
            dub/=10;
        }
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();++i){
            int curr=s[i]-'0';
            for(int i2=0;i2<m;++i2){
                if(curr==wanted[i2]){
                    dp[i2+1]+=dp[i2];
                }
            }
        }
    }
    dp[m].print();
return 0;
}