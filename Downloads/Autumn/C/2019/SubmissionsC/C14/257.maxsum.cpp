#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3,MAXK=1e3+3;
int num[MAXN],step[MAXK];
int sol(int l, int r, int sum, int k){
    int ans=sum;
    for(int i=0;i<k and l+step[i]<r;++i){
        ans=max(ans,sol(l+step[i],r,sum+num[l+step[i]],k));
    }
    for(int i=0;i<k and r-step[i]>l;++i){
        ans=max(ans,sol(l,r-step[i],sum+num[r-step[i]],k));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    for(int i=0;i<k;++i){
        cin>>step[i];
    }
    sort(step,step+k);
    cout<<sol(0,n-1,num[0]+num[n-1],k)<<endl;
return 0;
}
/**
9 2
3 2 6 6 0 2 4 5 5
3 2

6 2
1 4 7 2 5 1
3 4
**/
