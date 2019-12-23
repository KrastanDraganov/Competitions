#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;
vector<int> res;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int max_rem=-1,gcdx=-1;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        x-=y;
        if(x>0){
            gcdx=(gcdx<0 ? x : __gcd(gcdx,x));
        }
        max_rem=max(max_rem,y);
    }
    for(int i=1;i*i<=gcdx;++i){
        if(gcdx%i==0){
            if(i>max_rem){
                res.push_back(i);
            }
            if(i!=(gcdx/i) and (gcdx/i)>max_rem){
                res.push_back(gcdx/i);
            }
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
return 0;
}