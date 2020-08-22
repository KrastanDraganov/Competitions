#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

const long long BASE=1e9;

struct Long {
    
    int len;
    long long digits[64];
    
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

    void operator*=(const long long& num){
        long long carry=0;
        for(int i=0;i<len;++i){
            carry+=digits[i]*num;
            digits[i]=carry;
            if(carry>=BASE){
                digits[i]=carry%BASE;
                carry/=BASE;
            }else{
                digits[i]=carry;
                carry=0ll;
            }
        }
        while(carry){
            digits[len++]=carry%BASE;
            carry/=BASE;
        }
    }

    bool operator<=(const Long& comp){
        if(len==comp.len){
            for(int i=len-1;i>=0;--i){
                if(digits[i]>comp.digits[i]){
                    return false;
                }else if(digits[i]<comp.digits[i]){
                    return true;
                }
            }
            return true;
        }
        return len<comp.len;
    }
    
    void print(){
        fprintf(stdout,"%lld",digits[len-1]);
        for(int i=len-2;i>=0;--i){
            fprintf(stdout,"%09lld",digits[i]);
        }
        fprintf(stdout,"\n");
    }
};

Long parse_long(){
    string input;
    cin>>input;
    
    Long res;
    res.len=0;
    int counter=0;
    long long decimal=1;
    for(int i=input.size()-1;i>=0;--i){
        long long curr=input[i]-'0';
        res.digits[res.len]+=decimal*curr;
        if(counter>=8){
            counter=0;
            decimal=1;
            ++res.len;
        }else{
            ++counter;
            decimal*=10;
        }
    }
    if(counter>0){
        ++res.len;
    }
    return res;
}

bool check(int power, long long mul, Long& target){
    Long curr(1);
    for(int i=0;i<power;++i){
        curr*=mul;
    }
    return curr<=target;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Long a=parse_long();
    long long b;
    cin>>b;

    int l=0,r=400;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,b,a)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l-1<<endl;
return 0;
}