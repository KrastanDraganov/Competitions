#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int cattle[MAXN],houses[MAXN];

bool check(int diff, int n, int m, int k){
    int ind=0,capacity=k;
    for(int i=0;i<n;++i){
        if(capacity<=0){
            capacity=k;
            ++ind;
        }
        while(ind<m and cattle[i]-houses[ind]>diff){
            ++ind;
            capacity=k;
        }
        if(ind==m or houses[ind]-cattle[i]>diff){
            return false;
        }
        --capacity;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    
    for(int i=0;i<n;++i){
        cin>>cattle[i];
    }
    for(int i=0;i<m;++i){
        cin>>houses[i];
    }
    
    if((long long)m*k<(long long)n){
        cout<<"-1\n";
        return 0;
    }
    
    sort(cattle,cattle+n);
    sort(houses,houses+m);
    
    int l=0,r=1e6;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,n,m,k)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<r+1<<endl;
return 0;
}