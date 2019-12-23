#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int n,k;
        cin>>n>>k;
        vector<int> odd;
        for(int i2=0;i2<n;++i2){
            long long num;
            cin>>num;
            if(num%2==1){
                odd.push_back(i2+1);
            }
        }
        if(((int)odd.size()-k+1)%2==1 and ((int)odd.size()-k+1)>0){
            cout<<"YES\n";
            for(int i2=0;i2<k-1;++i2){
                cout<<odd[i2]<<" ";
            }
            cout<<n<<endl;
        }else{
            cout<<"NO\n";
        }
    }
return 0;
}