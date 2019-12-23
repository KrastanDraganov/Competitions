#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int> digits(n);
    for(int i=1;i<=n;++i){
        digits[i-1]=i;
    }
    int ans=0;
    do{
        bool check=true;
        for(int i=1;i<n;++i){
            if(abs(digits[i]-digits[i-1])>k){
                check=false;
                break;
            }
        }
        ans+=check;
    }while(next_permutation(digits.begin(),digits.end()));
    cout<<ans<<endl;
return 0;
}