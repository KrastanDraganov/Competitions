#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
int limit[MAXN];
bool check(int min_painted, int n, int k){
    int painted=0;
    for(int i=0;i<n;++i){
        int curr=min(max(min_painted,limit[i]-painted),k-painted);
        if(curr<min_painted){
            return false;
        }
        painted+=curr;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>limit[i];
    }
    sort(limit,limit+n);
    int l=0,r=limit[0];
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid,n,k)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
return 0;
}