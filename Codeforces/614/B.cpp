#include<iostream>
#include<iomanip>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double n;
    cin>>n;
    double res=0.0,nz=1;
    for(double i=1;i<=n;++i){
        double curr=nz/i;
        res+=curr;
    }
    cout<<res<<endl;
return 0;
}