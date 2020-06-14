#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,m;
        cin>>n>>m;

        int res=0;
        if(n==1){
            res=0;
        }else if(n==2){
            res=m;
        }else{
            res=2*m;
        }
        cout<<res<<endl;
    }
return 0;
}