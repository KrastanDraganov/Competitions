#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(a%b==0){
            cout<<0<<endl;
        }else{
            cout<<((a/b)+1)*b-a<<endl;
        }
    }
return 0;
}