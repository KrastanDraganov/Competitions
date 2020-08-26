#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=53;
long long seq_len[MAXN];

int digits(int num){
    int res=0;
    while(num>0){
        num/=10;
        ++res;
    }
    return res;
}

int sol(int n, long long k){
    for(int i=n;i>0;--i){
        int curr=digits(i);
        
        if(curr>=k){
            int counter=0,num=i;
            while(num>0){
                if(curr-counter==k){
                    return num%10;
                }
                num/=10;
                ++counter;
            }
        }
        
        k-=curr;
        if(i<=MAXN and k>seq_len[i-1]){
            k-=seq_len[i-1];
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    seq_len[1]=1;
    for(int i=2;i<MAXN;++i){
        seq_len[i]=2*seq_len[i-1]+digits(i);
    }
    
    int n;
    long long k;
    cin>>n>>k;
    
    cout<<sol(n,k)<<endl;
return 0;
}