#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
const int MAXN=1e5+3;
vector<int> price;
long long prefix_sum[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;++i){
        int curr;
        cin>>curr;
        price.push_back(curr);
    }
    sort(price.begin(),price.end());
    for(int i=1;i<=n;++i){
        prefix_sum[i]=prefix_sum[i-1]+(long long)price[i-1];
    }
    while(q--){
        long long m;
        int k;
        cin>>m>>k;
        int smaller=upper_bound(price.begin(),price.end(),k)-price.begin();
        int l=1,r=smaller+1;
        if(prefix_sum[smaller]<=m){
            cout<<smaller<<endl;
            continue;
        }
        while(l+1<r){
            int mid=(l+r+1)/2;
            //cout<<"curr: "<<l<<" "<<r<<" "<<mid<<" "<<prefix_sum[mid-1]<<endl;
            if(prefix_sum[smaller]-prefix_sum[mid-1]<=m){
                r=mid;
            }else{
                l=mid;
            }
        }
        cout<<smaller-r+1<<endl;
    }
return 0;
}