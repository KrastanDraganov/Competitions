// Not solved - 30 points, time limit

#include<iostream>
#include<vector>
#include<algorithm>

#define endl '\n'

using namespace std;

const int MAXN=1e5+3;
int nums[MAXN],pos[MAXN];
vector<int> tree[4*MAXN];

void build_tree(int ind, int tl, int tr){
    if(tl>tr){
        return;
    }

    if(tl==tr){
        tree[ind]=vector<int>{nums[tl]};
        return;
    }

    int mid=(tl+tr)/2;

    build_tree(2*ind, tl, mid);
    build_tree(2*ind+1, mid+1, tr);

    merge(tree[2*ind].begin(), tree[2*ind].end(),
          tree[2*ind+1].begin(), tree[2*ind+1].end(),
          back_inserter(tree[ind]));
}

void update_tree(int ind, int tl, int tr, int target){
    if(tl>tr){
        return;
    }

    if(tl==tr){
        tree[ind]={};
        return;
    }

    int mid=(tl+tr)/2;
    if(target<=mid){
        update_tree(2*ind, tl, mid, target);
    }else{
        update_tree(2*ind+1, mid+1, tr, target);
    }

    tree[ind].clear();
    merge(tree[2*ind].begin(), tree[2*ind].end(),
          tree[2*ind+1].begin(), tree[2*ind+1].end(),
          back_inserter(tree[ind]));
}

long long query(int ind, int tl, int tr, int l, int r, int target, int type){
    if(l>tr or r<tl or tl>tr or l>r){
        return 0;
    }

    if(tl==l and tr==r){
        long long res=0;
        if(type==0){
            auto it=upper_bound(tree[ind].begin(), tree[ind].end(), target);
            res=tree[ind].end()-it;
        }else{
            auto it=lower_bound(tree[ind].begin(), tree[ind].end(), target);
            res=(long long)tree[ind].size()-(tree[ind].end()-it);
        }
        return res;
    }

    int mid=(tl+tr)/2;
    return query(2*ind, tl, mid, l, min(mid, r), target, type)
            +query(2*ind+1, mid+1, tr, max(mid+1, l), r, target, type);
}

long long disorder_score(int n){
    long long res=0;
    for(int i=n-1;i>=0;--i){
        res+=query(1, 0, n-1, 0, i-1, nums[i], 0);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i){
        cin>>nums[i];
        pos[nums[i]-1]=i;
    }

    build_tree(1, 0, n-1);

    long long score=disorder_score(n);
    cout<<score<<" ";

    for(int i=2;i<n;++i){
        int removed;
        cin>>removed;

        int curr_pos=pos[removed-1];
        score-=query(1, 0, n-1, 0, curr_pos-1, nums[curr_pos], 0);
        score-=query(1, 0, n-1, curr_pos+1, n-1, nums[curr_pos], 1);
        cout<<score<<" ";

        update_tree(1, 0, n-1, curr_pos);
    }
    cout<<endl;
return 0;
}
