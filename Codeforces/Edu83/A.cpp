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
        cout<<(n%m==0 ? "YES" : "NO")<<endl;
    }
return 0;
}