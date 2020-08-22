#include<iostream>

#define endl '\n'

using namespace std;

long long sol(long long x, long long p, long long m){
    if(p==1){
        return x;
    }
    if(p%2==0){
        long long curr=sol(x,p/2,m)%m;
        return (curr*curr)%m;
    }
    return (x*(sol(x,p-1,m)%m))%m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,m;
    cin>>n>>m;
    
    cout<<sol(4,(n*n)/4,m)<<endl;
return 0;
}