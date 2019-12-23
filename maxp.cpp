#include<bits/stdc++.h>
#define endl '\n'
#define N 100005
using namespace std;
long long a[N],prefix_sums[N],l[N],r[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        prefix_sums[i+1]=a[i];
        if(i>0) prefix_sums[i+1]+=prefix_sums[i];
        l[i]=0;
        if(a[i]!=0)
        for(int i2=i-1;i2>=0;i2--){
            if(a[i2]<a[i]){
                l[i]=i2+1;
                break;
            }
        }
    }
    long long result=-1;
    for(int i=0;i<n;i++){
        r[i]=n-1;
        if(a[i]!=0)
        for(int i2=i+1;i2<n;i2++){
            if(a[i2]<a[i]){
                r[i]=i2-1;
                break;
            }
        }
        //cout<<i<<" "<<r[i]<<" "<<l[i]<<" ";
        long long curr=a[i]*(prefix_sums[r[i]+1]-prefix_sums[l[i]]);
        //cout<<curr<<endl;
        if(curr>result){
            result=curr;
        }
    }
    cout<<result<<endl;
return 0;
}