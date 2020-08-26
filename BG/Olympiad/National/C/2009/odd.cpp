#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long res;
    cin>>n>>res;
    
    for(int i=1;i<n;++i){
        long long num;
        cin>>num;
        res^=num;
    }
    cout<<res<<endl;
return 0;
}