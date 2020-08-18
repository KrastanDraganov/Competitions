#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k,s;
    cin>>k>>s;

    long long res=k,curr=k+1;
    while(curr<=s){
        s-=curr;
        ++curr;
    }
    --curr;
    long long diff=curr-k;
    while(s>=diff){
        s-=diff;
        ++res;
    }
    cout<<(s==0 ? res : res+1)<<endl;
return 0;
}