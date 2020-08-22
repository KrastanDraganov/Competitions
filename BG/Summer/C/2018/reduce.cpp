#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long last;
    cin>>n>>last;

    long long res=0;
    for(int i=1;i<n;++i){
        long long curr;
        cin>>curr;
        res+=max(curr,last);
        last=curr;
    }
    cout<<res<<endl;
return 0;
}