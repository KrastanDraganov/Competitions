#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int a,b;
        cin>>a>>b;
        int diff=max(a,b)-min(a,b);
        if((a>b and diff%2==1) or (a<b and diff%2==0)){
            cout<<2<<endl;
        }else if(a!=b){
            cout<<1<<endl;
        }else{
            cout<<0<<endl;
        }
    }
return 0;
}