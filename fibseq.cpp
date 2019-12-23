#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=n-1;i>=1;--i){
        swap(a,b);
        a=a-b;
    }
    cout<<a<<" "<<b<<endl;
return 0;
}