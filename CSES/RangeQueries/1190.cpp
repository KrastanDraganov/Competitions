#include<iostream>
#include<algorithm>

#define endl '\n'

using namespace std;

struct TreeData {
    long long sum,prefix,suffix,res;

    TreeData(){
        sum=prefix=suffix=res=0;
    }

    TreeData(int num){
        sum=prefix=suffix=res=num;
    }
};

const int MAXN=2e5+3;
int nums[MAXN];
TreeData tree[4*MAXN];

TreeData combine(TreeData l, TreeData r){
    TreeData ans;

    ans.sum=l.sum+r.sum;
    ans.prefix=max(l.prefix, l.sum+r.prefix);
    ans.suffix=max(r.suffix, r.sum+l.suffix);
    ans.res=max({l.suffix+r.prefix, l.res, r.res});

    return ans;
}

void build_tree(int ind, int l, int r){
    if(l==r){
        tree[ind]=TreeData(nums[l]);
        return;
    }

    int mid=(l+r)/2;
    build_tree(2*ind, l, mid);
    build_tree(2*ind+1, mid+1, r);

    tree[ind]=combine(tree[2*ind], tree[2*ind+1]);
}

void update_tree(int ind, int l, int r, int target){
    if(l==r){
        tree[ind]=TreeData(nums[l]);
        return;
    }

    int mid=(l+r)/2;
    if(target<=mid){
        update_tree(2*ind, l, mid, target);
    }else{
        update_tree(2*ind+1, mid+1, r, target);
    }

    tree[ind]=combine(tree[2*ind], tree[2*ind+1]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    build_tree(1, 0, n-1);

    for(int i=0;i<m;++i){
        int ind,new_val;
        cin>>ind>>new_val;

        --ind;
        nums[ind]=new_val;
        update_tree(1, 0, n-1, ind);

        cout<<max(0ll, tree[1].res)<<endl;
    }
return 0;
}