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
        cout<<1<<" "<<num-1<<endl;
    }
return 0;
}