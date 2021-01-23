#include<iostream>
#include<iomanip>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    while(cin>>n>>m and !(n==0 and m==0)){
        double res=(n>m ? 0.0 : double(m+1-n)/(m+1));
        cout<<fixed<<setprecision(6)<<res<<endl;
    }
return 0;
}