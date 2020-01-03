#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        cin>>n>>k;
        int res=(n/k)*k;
        if(n%k>k/2){
            res+=(k/2);
        }else{
            res+=(n%k);
        }
        cout<<res<<endl;
    }
return 0;
}