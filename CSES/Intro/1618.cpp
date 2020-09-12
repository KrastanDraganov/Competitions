#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int res=0;
    for(int i=5;i<=n;i*=5){
        res+=(n/i);
    }
    cout<<res<<endl;
return 0;
}