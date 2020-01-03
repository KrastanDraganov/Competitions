#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=2e5+3;
int cord[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>cord[i];
    }
    sort(cord,cord+n);
    int prev=-1,res_min=0,res_max=0;
    for(int i=0;i<n;++i){
        if(cord[i]-1>prev){
            prev=cord[i]+1;
            ++res_min;
        }
    }
    prev=-1;
    for(int i=0;i<n;++i){
        for(int i2=-1;i2<=1;++i2){
            if(cord[i]+i2>prev){
                prev=cord[i]+i2;
                ++res_max;
                break;
            }
        }
    }
    cout<<res_min<<" "<<res_max<<endl;
return 0;
}