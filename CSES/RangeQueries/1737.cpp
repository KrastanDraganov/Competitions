#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

struct TreeNode {
    long long sum;
    TreeNode *l,*r;

    TreeNode(){
        l=r=nullptr;
        sum=0;
    }

    TreeNode(int val) : sum(val) {
        l=r=nullptr;
    }

    TreeNode(TreeNode* _l, TreeNode* _r) : l(_l), r(_r) {
        sum=0;
        if(l){
            sum+=l->sum;
        }
        if(r){
            sum+=r->sum;
        }
    }
};

const int MAXN=2e5+3;
int nums[MAXN];

TreeNode* build_tree(int tl, int tr){
    if(tl==tr){
        return new TreeNode(nums[tl]);
    }

    int mid=(tl+tr)/2;
    return new TreeNode(build_tree(tl, mid), build_tree(mid+1, tr));
}

TreeNode* update_tree(TreeNode* curr, int tl, int tr, int target, int new_val){
    if(tl==tr){
        return new TreeNode(new_val);
    }

    int mid=(tl+tr)/2;
    if(target<=mid){
        return new TreeNode(update_tree(curr->l, tl, mid, target, new_val), curr->r);
    }else{
        return new TreeNode(curr->l, update_tree(curr->r, mid+1, tr, target, new_val));
    }
}

long long query(TreeNode* curr, int tl, int tr, int l, int r){
    if(l>tr or r<tl or l>r){
        return 0;
    }

    if(l==tl and r==tr){
        return curr->sum;
    }

    int mid=(tl+tr)/2;
    return query(curr->l, tl, mid, l, min(mid, r))
        +query(curr->r, mid+1, tr, max(mid+1, l), r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin>>n>>q;

    for(int i=0;i<n;++i){
        cin>>nums[i];
    }

    vector<TreeNode*> roots;
    roots.push_back(build_tree(0, n-1));

    while(q--){
        int type,array_ind;
        cin>>type>>array_ind;
        --array_ind;

        if(type==1){
            int pos,new_val;
            cin>>pos>>new_val;
            --pos;

            roots[array_ind]=update_tree(roots[array_ind], 0, n-1, pos, new_val);
        }else if(type==2){
            int l,r;
            cin>>l>>r;
            --l;
            --r;

            cout<<query(roots[array_ind], 0, n-1, l, r)<<endl;
        }else{
            roots.push_back(roots[array_ind]);
        }
    }
return 0;
}