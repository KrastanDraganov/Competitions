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
        n/=2;
        if(n%2==1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            int sum=0,curr=2;
            for(int i=0;i<n;++i){
                cout<<curr<<" ";
                sum+=curr;
                curr+=2;
            }
            int sum2=0;
            curr=1;
            for(int i=n;i<2*n-1;++i){
                cout<<curr<<" ";
                sum2+=curr;
                curr+=2;
            }
            cout<<sum-sum2<<endl;
        }
    }
return 0;
}