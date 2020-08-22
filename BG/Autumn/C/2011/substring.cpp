#include<iostream>

#define endl '\n'

using namespace std;

const int MOD=123456789;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,a,b;
    cin>>n>>a>>b;
    
    cout<<((n-a+1)*a+(n-b+1)*(b-a))%MOD<<endl;
return 0;
}