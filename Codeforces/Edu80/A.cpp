#include<iostream>
#define endl '\n'
using namespace std;
int main(){
    int tests;
    cin>>tests;
    while(tests--){
        int n,d;
        cin>>n>>d;
        int res=d;
        for(int i=0;i<=1e5;++i){
            res=min(res,i+((d+i)/(i+1)));
        }
        cout<<(res<=n ? "YES" : "NO")<<endl;
    }
return 0;
}