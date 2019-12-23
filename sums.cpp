#include<iostream>
#define endl '\n'
using namespace std;
const int MAXN = 1e6+3;
int nums[MAXN];
bool used[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    used[0]=true;
    for(int i=0;i<n;++i){
        for(int i2=b;i2>0;--i2){
            if(i2-nums[i]>=0 and used[i2-nums[i]]){
                used[i2]=true;
            }
        }
    }
    int res=0;
    for(int i=a;i<=b;++i){
        res+=used[i];
    }
    cout<<res<<endl;
return 0;
}