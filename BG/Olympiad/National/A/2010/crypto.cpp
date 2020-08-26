#include<iostream>
#include<cstring>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=403,BASE=1e9;

struct Long {
    int len,digits[16];
    
    Long(){
        len=1;
        memset(digits,0,sizeof(digits));
    }
    
    Long(long long num){
        len=(int)(num<1);
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
    
    void operator-=(const Long& num){
        for(int i=len-1;i>=0;--i){
            digits[i]-=num.digits[i];
        }
        for(int i=0;i<len;++i){
            if(digits[i]<0){
                digits[i]+=BASE;
                --digits[i+1];
            }
        }
        while(len>1 and digits[len-1]==0){
            --len;
        }
    }
    
    void operator+=(const Long& num){
        len=max(len,num.len);
        int carry=0;
        for(int i=0;i<len;++i){
            carry+=digits[i]+num.digits[i];
            if(carry>=BASE){
                digits[i]=carry-BASE;
                carry=1;
            }else{
                digits[i]=carry;
                carry=0;
            }
        }
        if(carry){
            digits[len++]=carry;
        }
    }
    
    void divide2(){
        for(int i=0;i<len;++i){
            digits[i]/=2;
            if(i<len-1 and digits[i+1]%2==1){
                digits[i]+=(BASE/2);
            }
        }
        while(len>1 and digits[len-1]==0){
            --len;
        }
    }
    
    bool parity(){
        return digits[0]%2==1;
    }
    
    bool not_zero(){
        return len>1 or digits[0]!=0;
    }
    
    void print(){
        fprintf(stdout,"%d",digits[len-1]);
        for(int i=len-2;i>=0;--i){
            fprintf(stdout,"%09d",digits[i]);
        }
        fprintf(stdout,"\n");
    }
} dp[MAXN][MAXN][2][2];

bool visited[MAXN][MAXN][2][2];
vector<bool> num1,num2;

Long parse_long(){
    string s;
    cin>>s;
    
    Long res;
    res.len=0;
    
    int ind=0,decimal=1;
    for(int i=s.size()-1;i>=0;--i){
        res.digits[res.len]+=decimal*(s[i]-'0');
        if(ind>=8){
            ind=0;
            decimal=1;
            ++res.len;
        }else{
            ++ind;
            decimal*=10;
        }
    }
    if(ind!=0){
        ++res.len;
    }
    return res;
}

Long calc(int ind, int counter, bool check1, bool check2, int k){
    if(counter>=k){
        return 0;
    }
    if(ind<0){
        return 1;
    }

    Long& res=dp[ind][counter][check1][check2];
    if(visited[ind][counter][check1][check2]){
        return res;
    }
    
    res=0;
    if(check1 or num1[ind]==0){
        res+=calc(ind-1,0,check1,check2 or num2[ind]==1,k);
    }
    if(check2 or num2[ind]==1){
        res+=calc(ind-1,counter+1,check1 or num1[ind]==0,check2,k);
    }
    
    visited[ind][counter][check1][check2]=true;
    return res;
}

Long calc_ans(Long lnum, Long rnum, int k){
    Long res=rnum;
    res-=lnum;
    res+=1;
    
    while(lnum.not_zero()){
        num1.push_back(lnum.parity());
        lnum.divide2();
    }
    
    while(rnum.not_zero()){
        num2.push_back(rnum.parity());
        rnum.divide2();
    }
    
    if(k>num2.size()){
        return 0;
    }
    res-=calc(num2.size()-1,0,false,false,k);
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin>>k;
    
    Long lnum=parse_long(),rnum=parse_long();
    Long ans=calc_ans(lnum,rnum,k);
    ans.print();
return 0;
}