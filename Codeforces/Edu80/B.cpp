#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    int tests;
    cin>>tests;
    while(tests--){
        long long a,b;
        cin>>a>>b;
        long long res=0;
        for(long long i=9;i<=b;i=10*i+9){
            res+=a;
        }
        cout<<res<<endl;
    }
return 0;
}