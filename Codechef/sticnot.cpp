#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int vertices[MAXN],edges[MAXN];

bool check(int coins, int n){
    for(int i=0;i+coins<n;++i){
        if(edges[i]>vertices[i+coins]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;
        for(int i=0;i<n-1;++i){
            int from,to;
            cin>>from>>to>>edges[i];
        }
        for(int i=0;i<n;++i){
            cin>>vertices[i];
        }

        sort(vertices,vertices+n);
        sort(edges,edges+n-1);
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,n)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<(r+1)<<endl;
    }
}