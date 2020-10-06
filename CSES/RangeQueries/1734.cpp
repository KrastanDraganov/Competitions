#include<iostream>
#include<math.h>
#include<algorithm>
#include<map>

#define endl '\n'

using namespace std;

const int MAXN=2e5+3;
const int BLOCK_SIZE=sqrt(MAXN);
int nums[MAXN],res[MAXN],counter[MAXN];

struct Query {
    int l,r,ind;

    Query(){
        l=r=ind=-1;
    }

    Query(int _l, int _r, int _ind){
        l=_l;
        r=_r;
        ind=_ind;
    }

    bool operator<(const Query& comp) {
        int block1=l/BLOCK_SIZE;
        int block2=comp.l/BLOCK_SIZE;
        
        if(block1==block2){
            return (!(block1 & 1) ? r<comp.r : r>comp.r);
        }
        return block1<block2;
    }
} queries[MAXN];


void add_num(int num, int& curr_res){
    if(counter[num]==0){
        ++curr_res;
    }
    ++counter[num];
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

    int n,q;
    cin>>n>>q;

    map<int, int> compressed;
    int new_num=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        if(!compressed.count(nums[i])){
            compressed[nums[i]]=new_num++;
        }
        nums[i]=compressed[nums[i]];
    }

    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        queries[i]=Query(l-1, r-1, i);
    }
    sort(queries,queries+q);

    int curr_l=queries[0].l,curr_r=queries[0].r;
    int curr_res=0;
    for(int i=curr_l;i<=curr_r;++i){
        add_num(nums[i], curr_res);
    }
    res[queries[0].ind]=curr_res;

    for(int i=1;i<q;++i){
        while(queries[i].l<curr_l){
            --curr_l;
            add_num(nums[curr_l], curr_res);
        }
        while(curr_r<queries[i].r){
            ++curr_r;
            add_num(nums[curr_r], curr_res);
        }

        while(curr_l<queries[i].l){
            remove_num(nums[curr_l], curr_res);
            ++curr_l;
        }
        while(queries[i].r<curr_r){
            remove_num(nums[curr_r], curr_res);
            --curr_r;
        }

        res[queries[i].ind]=curr_res;
    }

    for(int i=0;i<q;++i){
        cout<<res[i]<<endl;
    }
return 0;
}