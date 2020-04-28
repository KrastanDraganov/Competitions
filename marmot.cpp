#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,l,k;
    cin>>n>>l>>k;
    ++k;
    int res=0;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        curr=l-curr;
        res^=(curr%k);
    }
    cout<<(!res ? "NO" : "YES")<<endl;
return 0;
}