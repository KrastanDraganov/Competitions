// Not solved - 57 points, wrong answer
// Solving with DSU with erasing

#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<stack>

#define endl '\n'

using namespace std;

struct Change {
    int time,prev_val;
    int* address;

    Change(int _time=-1, int* _address=nullptr, int _prev_val=-1){
        time=_time;
        address=_address;
        prev_val=_prev_val;
    }
};

const int MAXN=1e5+3,MAXQ=12e4+3;
int parent[MAXN],depth[MAXN];
pair<int, int> questions[MAXQ];
vector<pair<int, int>> tree[4*MAXQ];
stack<Change> changes;

int find_parent(int num){
    if(num==parent[num]){
        return num;
    }
    return find_parent(parent[num]);
}

void combine(pair<int, int> edge, int timer){
    int root1=find_parent(edge.first);
    int root2=find_parent(edge.second);

    if(root1==root2){
        return;
    }

    if(depth[root2]>depth[root1]){
        swap(root1, root2);
    }

    changes.push(Change(timer, parent+root2, parent[root2]));
    parent[root2]=root1;

    if(depth[root1]==depth[root2]){
        changes.push(Change(timer, depth+root1, depth[root1]));
        ++depth[root1];
    }
}

bool are_combined(pair<int, int> edge){
    return find_parent(edge.first)==find_parent(edge.second);
}

void undo_changes(int target_time){
    while(!changes.empty() and changes.top().time==target_time){
        Change curr=changes.top();
        changes.pop();
        *(curr.address)=curr.prev_val;
    }
}

void update_tree(int ind, int tl, int tr, int l, int r, pair<int, int> edge){
    if(tl>r or tr<l or l>r){
        return;
    }

    if(l==tl and r==tr){
        tree[ind].push_back(edge);
        return;
    }

    int mid=(tl+tr)/2;
    update_tree(2*ind, tl, mid, l, min(mid, r), edge);
    update_tree(2*ind+1, mid+1, tr, max(mid+1, l), r, edge);
}

void answer_questions(int ind, int tl, int tr){
    for(pair<int, int> edge : tree[ind]){
        combine(edge, ind);
    }

    if(tl==tr){
        if(questions[tl]!=make_pair(-1, -1)){
            cout<<are_combined(questions[tl]);
        }
    }else{
        int mid=(tl+tr)/2;
        answer_questions(2*ind, tl, mid);
        answer_questions(2*ind+1, mid+1, tr);
    }

    undo_changes(ind);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    map<pair<int, int>, int> added_edge;
    for(int i=0;i<m;++i){
        int from,to;
        cin>>from>>to;
        --from;
        --to;
        added_edge[{from, to}]=0;
    }

    int q;
    cin>>q;

    for(int i=0;i<=q;++i){
        questions[i]={-1, -1};
    }

    for(int i=1;i<=q;++i){
        int type,from,to;
        cin>>type>>from>>to;
        
        --from;
        --to;
        if(from>to){
            swap(from, to);
        }

        if(type==1){
            questions[i]={from, to};
            continue;
        }

        if(type==3){
            if(!added_edge.count({from, to})){
                added_edge[{from, to}]=i;
            }
            continue;
        }

        if(!added_edge.count({from, to})){
            continue;
        }

        int curr_add=added_edge[{from, to}];
        update_tree(1, 0, q, curr_add, i, {from, to});
        added_edge.erase({from, to});
    }

    for(auto curr : added_edge){
        update_tree(1, 0, q, curr.second, q, curr.first);
    }

    for(int i=0;i<n;++i){
        parent[i]=i;
        depth[i]=1;
    }

    answer_questions(1, 0, q);
    cout<<endl;
return 0;
}