#include<iostream>

#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n,k;
        cin>>n>>k;

        int res=(n<=k ? 1 : n);
        for(int div=2;div*div<=n;++div){
            if(n%div==0){
                int other=n/div;
                if(other<=k){
                    res=min(res,div);
                }else if(div<=k){
                    res=min(res,other);
                }
            }
        }
        cout<<res<<endl;
    }
return 0;
}