#include<iostream>
#include<vector>

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

        if(n%2==k%2){
            int curr=(n-k+1);
            if(curr<=0 or curr%2==0){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                for(int i=0;i<k-1;++i){
                    cout<<1<<" ";
                }
                cout<<curr<<endl;
            }
        }else{
            int curr=(n-(k-1)*2);
            if(curr<=0 or curr%2==1){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
                for(int i=0;i<k-1;++i){
                    cout<<2<<" ";
                }
                cout<<curr<<endl;
            }
        }
    }
return 0;
}