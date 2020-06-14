#include<iostream>
#include<queue>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
int res[MAXN];

struct Interval {
    int l,r,len;
    
    Interval(){
        l=-1;
        r=-1;
        len=0;
    }
    
    Interval(int _l, int _r){
        l=_l;
        r=_r;
        len=r-l+1;
    }
    
    bool operator<(const Interval& comp) const {
        if(len==comp.len){
            return l>comp.l;
        }
        return len<comp.len;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin>>tests;
    while(tests--){
        int n;
        cin>>n;

        priority_queue<Interval,vector<Interval>> halfs;
        halfs.push(Interval(0,n-1));
        for(int i=1;i<=n;++i){
            Interval curr=halfs.top();
            halfs.pop();
            int mid=-1;
            if(curr.len%2==0){
                mid=(curr.l+curr.r-1)/2;
            }else{
                mid=(curr.l+curr.r)/2;
            }
            res[mid]=i;
            if(curr.l<mid){
                halfs.push(Interval(curr.l,mid-1));
            }
            if(mid<curr.r){
                halfs.push(Interval(mid+1,curr.r));
            }
        }

        for(int i=0;i<n;++i){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}