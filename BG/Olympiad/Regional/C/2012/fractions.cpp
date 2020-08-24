#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long n;
    cin>>n;
    
    unsigned long long a=1,b=1,c=2;
    for(unsigned long long i=3;i<=n;++i){
        unsigned long long curr=(i*c)/__gcd(i,c);
        b=b*(curr/c)+(curr/i);
        c=curr;
        unsigned long long del=__gcd(b,c);
        b/=del;
        c/=del;
        if(b>c){
            a+=(b/c);
            b=b%c;
        }
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
return 0;
}