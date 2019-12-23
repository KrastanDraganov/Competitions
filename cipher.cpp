#include<iostream>
#define endl '\n'
using namespace std;
long long m;
long long sol(long long x, long long p){
    if(p==1){
        return x;
    }
    if(p%2==0){
        long long curr=sol(x,p/2)%m;
        return (curr*curr)%m;
    }else{
        return (x*(sol(x,p-1)%m))%m;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n>>m;
    cout<<sol(4,(n*n)/4)<<endl;
return 0;
}