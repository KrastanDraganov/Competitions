// Not solved - 59 points, time limit

#include<iostream>
#include<vector>

#define endl '\n'

using namespace std;

const int MAXN=5e4+3,MAXM=5e3;
vector<int> divs[MAXN];
long long nums[MAXN],sums[MAXN],tree[4*MAXN];

vector<int> find_divs(int num){
    vector<int> res;

    for(int i=1;i*i<=num;++i){
        if(num%i!=0){
            continue;
        }

        int curr_div=num/i;
        res.push_back(curr_div);

        if(num/curr_div!=curr_div){
            res.push_back(num/curr_div);
        }
    }

    return res;
}

void build_tree(int ind, int tl, int tr){
    if(tl==tr){
        tree[ind]=sums[tl];
        return;
    }

    int mid=(tl+tr)/2;
    build_tree(2*ind, tl, mid);
    build_tree(2*ind+1, mid+1, tr);

    tree[ind]=max(tree[2*ind], tree[2*ind+1]);
}

void update_tree(int ind, int tl, int tr, int pos, long long val){
    if(tl==tr){
        tree[ind]+=val;
        return;
    }

    int mid=(tl+tr)/2;
    if(pos<=mid){
        update_tree(2*ind, tl, mid, pos, val);
    }else{
        update_tree(2*ind+1, mid+1, tr, pos, val);
    }

    tree[ind]=max(tree[2*ind], tree[2*ind+1]);
}

long long subtask4(int n, int q){
    long long max_sum=sums[0];
    for(int i=1;i<n;++i){
        max_sum=max(max_sum, sums[i]);
    }

    long long res=0;
    while(q--){
        int pos;
        long long val;
        cin>>pos>>val;

        long long curr=max_sum;
        for(int div : divs[pos]){
            curr=max(curr, sums[div-1]+val);
        }

        res+=curr;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1;i<=n;++i){
        divs[i]=find_divs(i);
    }

    for(int i=0;i<n;++i){
        cin>>nums[i];
        for(int div : divs[i+1]){
            sums[div-1]+=nums[i];
        }
    }

    int q;
    cin>>q;

    if(q>MAXM){
        cout<<subtask4(n, q)<<endl;
        return 0;
    }

    build_tree(1, 0, n-1);

    long long res=0;
    while(q--){
        int pos;
        long long val;
        cin>>pos>>val;

        for(int div : divs[pos]){
            update_tree(1, 0, n-1, div-1, val);
        }
        res+=tree[1];


        for(int div : divs[pos]){
            update_tree(1, 0, n-1, div-1, -val);
        }
    }

    cout<<res<<endl;
return 0;
}
