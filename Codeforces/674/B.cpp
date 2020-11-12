#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;

    while(tests--){
        int n,m;
        cin>>n>>m;
        
        bool check=false;
        for(int i=0;i<n;++i){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            check |= (b==c);
        }
        check &= (m%2==0);

        cout<<(check ? "YES" : "NO")<<endl;
    }
return 0;
}