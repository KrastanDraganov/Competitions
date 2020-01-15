#include<iostream>
#include<cstring>
#define endl '\n'
using namespace std;
const int MAXN=3e5+3,MAXM=(1<<8);
int nums[MAXN][11],masks[MAXM];
bool check(int mid, int& res1, int& res2, int n, int m){
    memset(masks,-1,sizeof(masks));
    for(int i=0;i<n;++i){
        int curr=0;
        for(int i2=0;i2<m;++i2){
            if(nums[i][i2]>=mid){
                curr |= (1<<i2);
            }
        }
        masks[curr]=i;
    }
    if(masks[(1<<m)-1]>-1){
        res1=res2=masks[(1<<m)-1]+1;
        return true;
    }
    for(int i=0;i<(1<<m);++i){
        for(int i2=0;i2<(1<<m);++i2){
            if(masks[i]>-1 and masks[i2]>-1 and (i | i2)==(1<<m)-1){
                res1=masks[i]+1;
                res2=masks[i2]+1;
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int i2=0;i2<m;++i2){
            cin>>nums[i][i2];
        }
    }
    int l=0,r=1e9+3,res1=1,res2=1;
    while(l+1<r){
        int mid=(l+r)/2;
        if(check(mid,res1,res2,n,m)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<res1<<" "<<res2<<endl;
return 0;
}