#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=203,BASE=1e9;
struct Long {
    int len,digits[53];
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
} dp[MAXN][2003];
bool visited[MAXN][2003],already[203];
int value[MAXN],counter[MAXN],value_ind[203];
Long calc(int ind, int sum, int s, int n){
    if(sum==s){
        return 1;
    }
    if(ind>=n or sum>s){
        return 0;
    }
    if(visited[ind][sum]){
        return dp[ind][sum];
    }
    Long& ans=dp[ind][sum];
    for(int i=0;i<=counter[ind] and sum+i*value[ind]<=s;++i){
        ans+=calc(ind+1,sum+i*value[ind],s,n);
    }
    visited[ind][sum]=true;
    return ans;
}
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
    Long ans=calc(0,0,s,n);
    ans.print();
return 0;
}