#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;

        long long res=0;
        for(int i=n/2;i>0;--i){
            res+=(long long) i*4*(n-1);
            n-=2;
        }
        cout<<res<<endl;
    }
return 0;
}