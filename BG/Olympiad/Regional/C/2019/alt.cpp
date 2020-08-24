#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN=103;
unsigned long long dp[MAXN][MAXN];

unsigned long long sol(int num, int length, int k, int m, int n){
    if(num<1 or num>=m){ 
        return 0;
    }
    if(length>n){ 
        return 0;
    }
    if(length==n){ 
        return 1;
    }
    
    unsigned long long& res=dp[num][length];
    if(res!=0){ 
        return res;
    }
    
    res=sol(num-k,length+1,k,m,n)+sol(num+k,length+1,k,m,n);
    if(length==1){ 
        res+=sol(num-1,length,k,m,n);
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k,m,n;
    cin>>k>>m>>n;
    
    cout<<sol(m-1,1,k,m,n)<<endl;
return 0;
}