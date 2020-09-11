#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    long long sum=(long long)n*(n+1)/2;
    long long curr=0;
    for(int i=0;i<n-1;++i){
        int num;
        cin>>num;
        curr+=(long long) num;
    }
    cout<<sum-curr<<endl;
return 0;
}