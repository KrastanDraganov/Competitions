#include<iostream>
#include<random>
#include<chrono>
#include<array>

#define endl '\n'

using namespace std;

const int INF = 1e9+3;
mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
    int val, priority;
    int subtree_size;
    bool is_reversed;
    array<Treap*, 2> kids;

    Treap(int _val){
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size = 1;
        is_reversed = false;
        kids[0] = kids[1] = nullptr;
    }
};

Treap* treap = nullptr;

int treap_size(Treap* curr){
    return curr ? curr->subtree_size : 0;
}

void recover(Treap* curr){
    if(!curr){
        return;
    }

    curr->subtree_size = 1;
    for(Treap* kid : curr->kids){
        curr->subtree_size += treap_size(kid);
    }
}

void push_lazy(Treap* curr){
    if(!curr or !curr->is_reversed){
        return;
    }

    swap(curr->kids[0], curr->kids[1]);
    curr->is_reversed = false;

    for(Treap* kid : curr->kids){
        if(kid){
            kid->is_reversed ^= 1;
        }
    }
}

array<Treap*, 2> split_by_pos(Treap* curr, int pos){
    if(!curr){
        return {nullptr, nullptr};
    }

    push_lazy(curr);

    if(pos <= treap_size(curr->kids[0])){
        array<Treap*, 2> left_split = split_by_pos(curr->kids[0], pos);
        curr->kids[0] = left_split[1];
        recover(curr);
        return {left_split[0], curr};
    }else{
        array<Treap*, 2> right_split = split_by_pos(curr->kids[1], pos - treap_size(curr->kids[0]) - 1);
        curr->kids[1] = right_split[0];
        recover(curr);
        return {curr, right_split[1]};
    }
}

Treap* merge(Treap* l, Treap* r){
    if(!l){
        return r;
    }

    if(!r){
        return l;
    }

    push_lazy(l);
    push_lazy(r);

    if(l->priority < r->priority){
        l->kids[1] = merge(l->kids[1], r);
        recover(l);
        return l;
    }else{
        r->kids[0] = merge(l, r->kids[0]);
        recover(r);
        return r;
    }
}

Treap* cyclic_shift(Treap* treap, int from, int to){
    array<Treap*, 2> split_point1 = split_by_pos(treap, from);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], to - from + 1);

    Treap* interval = split_point2[0];
    array<Treap*, 2> split_point3 = split_by_pos(interval, to - from);

    return merge(split_point1[0], merge(split_point3[1], merge(split_point3[0], split_point2[1])));
}

Treap* reverse_treap(Treap* treap, int from, int to){
    array<Treap*, 2> split_point1 = split_by_pos(treap, from);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], to - from + 1);

    Treap* interval = split_point2[0];
    if(interval){
        interval->is_reversed ^= 1;
    }

    return merge(split_point1[0], merge(split_point2[0], split_point2[1]));
}

int kth_element(Treap* curr, int pos){
    if(!curr){
        return INF;
    }

    push_lazy(curr);

    if(treap_size(curr->kids[0]) >= pos){
        return kth_element(curr->kids[0], pos);
    }

    if(treap_size(curr->kids[0]) + 1 == pos){
        return curr->val;
    }

    return kth_element(curr->kids[1], pos - treap_size(curr->kids[0]) - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, m;
    cin>>n>>q>>m;

    for(int i = 0; i < n; ++i){
        int num;
        cin>>num;

        Treap* curr_node = new Treap(num);
        treap = merge(treap, curr_node);
    }

    for(int i = 0; i < q; ++i){
        int type, from, to;
        cin>>type>>from>>to;

        --from;
        --to;

        if(type == 1){
            treap = cyclic_shift(treap, from, to);
        } else {
            treap = reverse_treap(treap, from, to);
        }
    }

    for(int i = 0; i < m; ++i){
        int pos;
        cin>>pos;

        cout<<kth_element(treap, pos)<<" ";
    }
    cout<<endl;
return 0;
}