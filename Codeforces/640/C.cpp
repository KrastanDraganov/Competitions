#include<iostream>

#define endl '\n'

using namespace std;

bool check(long long mid, long long k, long long n){
    if(mid==0){
        return false;
    }
    long long div=mid/n;
    long long counter=div*(n-1)+(mid-div*n);
    return counter>=k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        long long n,k;
        cin>>n>>k;

        long long l=0,r=1e18;
        while(l<=r){
            long long mid=(l+r)/2;
            if(check(mid,k,n)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<r+1<<endl;
    }
return 0;
}