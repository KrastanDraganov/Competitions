#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,x,b,y;
    cin>>n>>a>>x>>b>>y;
    if(a==b){
        cout<<"YES"<<endl;
        return 0;
    }
    while(a!=x and b!=y){
        if(a==n){
            a=1;
        }else{
            ++a;
        }
        if(b==1){
            b=n;
        }else{
            --b;
        }
        if(a==b){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
return 0;
}