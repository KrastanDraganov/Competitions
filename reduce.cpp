#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    long long last,curr,res=0;
    cin>>last;
    for(int i=1;i<n;++i){
        cin>>curr;
        res+=max(curr,last);
        last=curr;
    }
    cout<<res<<endl;
return 0;
}