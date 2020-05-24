#include<iostream>
#include<utility>
#include<algorithm>
#include<math.h>

#define endl '\n'

using namespace std;

const int MAXN=3e4+3,MAXS=1e6+3,MAXQ=2e5+3;
int nums[MAXN],counter[MAXS],res[MAXQ],block_size;
struct Query {
    int l,r,ind;
    Query(){
        l=-1;
        r=-1;
        ind=-1;
    }
    Query(int _l, int _r, int _ind){
        l=_l;
        r=_r;
        ind=_ind;
    }
    bool operator<(Query comp){
        if((l/block_size)==(comp.l/block_size)){
            return r<comp.r;
        }
        return (l/block_size)<(comp.l/block_size);
    }
} queries[MAXQ];

void add_num(int num, int& curr_res){
    ++counter[num];
    if(counter[num]==1){
        ++curr_res;
    }
}

void remove_num(int num, int& curr_res){
    --counter[num];
    if(counter[num]==0){
        --curr_res;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        queries[i]=Query(l,r,i);
    }

    block_size=sqrt(n);
    sort(queries,queries+q);
    int l=-1,r=-1,curr_res=0;
    for(int i=0;i<q;++i){
        Query curr=queries[i];
        if(i==0){
            l=curr.l;
            r=curr.r;
            for(int i2=l;i2<=r;++i2){
                add_num(nums[i2],curr_res);
            }
        }else{
            while(l>curr.l){
                --l;
                add_num(nums[l],curr_res);
            }
            while(l<curr.l){
                remove_num(nums[l],curr_res);
                ++l;
            }
            while(r>curr.r){
                remove_num(nums[r],curr_res);
                --r;
            }
            while(r<curr.r){
                ++r;
                add_num(nums[r],curr_res);
            }
        }
        res[curr.ind]=curr_res;
    }

    for(int i=0;i<q;++i){
        cout<<res[i]<<endl;
    }
return 0;
}