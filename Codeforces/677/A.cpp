#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int num;
        cin>>num;

        int digits=0,curr=num%10;
        while(num>0){
            ++digits;
            num/=10;
        }

        cout<<10*(curr-1)+digits*(digits+1)/2<<endl;
    }
return 0;
}