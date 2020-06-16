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
        int odd=0,even=0;
        for(int i=0;i<n;++i){
            int curr;
            cin>>curr;
            if(curr%2!=i%2){
                if(i%2==0){
                    ++even;
                }else{
                    ++odd;
                }
            }
        }
        cout<<(odd==even ? even : -1)<<endl;
    }
return 0;
}