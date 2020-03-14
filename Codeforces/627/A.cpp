#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        bool check=false,check2=false;
        for(int i=0;i<n;++i){
            int height;
            cin>>height;
            if(height%2==0){
                check=true;
            }else{
                check2=true;
            }
        }
        cout<<((check and check2) ? "NO" : "YES")<<endl;
    }
return 0;
}