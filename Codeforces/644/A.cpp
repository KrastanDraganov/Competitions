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
        int mina=min(a,b);
        int maxa=max(a,b);
        if(2*mina>=maxa){
            cout<<4*mina*mina<<endl;
        }else{
            cout<<maxa*maxa<<endl;
        }
    }
return 0;
}