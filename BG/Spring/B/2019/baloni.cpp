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
    int left_color, right_color, query;
    array<Treap*, 2> kids;

    Treap(int _val){
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size = 1;
        left_color = right_color = _val;
        query = 1;
        kids[0] = kids[1] = nullptr;
    }
};

Treap* treap = nullptr;

int treap_size(Treap* curr){
    return curr ? curr->subtree_size : 0;
}

int treap_query(Treap* curr){
    return curr ? curr->query : 0;
}

void recover(Treap* curr){
    if(!curr){
        return;
    }

    curr->subtree_size = 1;
    curr->query = 0;

    for(Treap* kid : curr->kids){
        curr->subtree_size += treap_size(kid);
        curr->query += treap_query(kid);
    }

    int same_colors = 0;
    if(curr->kids[0] and (curr->val == curr->kids[0]->right_color)){
        ++same_colors;
    }
    if(curr->kids[1] and (curr->val == curr->kids[1]->left_color)){
        ++same_colors;
    }

    if(same_colors == 2){
        --curr->query;
    } else if(same_colors == 0){
        ++curr->query;
    }

    curr->left_color = (curr->kids[0] ? curr->kids[0]->left_color : curr->val);
    curr->right_color = (curr->kids[1] ? curr->kids[1]->right_color : curr->val);
}

array<Treap*, 2> split_by_pos(Treap* curr, int pos){
    if(!curr){
        return {nullptr, nullptr};
    }

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

Treap* insert_balloon(Treap* treap, int pos, int color){
    array<Treap*, 2> split_point = split_by_pos(treap, pos);

    Treap* new_node = new Treap(color);
    return merge(split_point[0], merge(new_node, split_point[1]));
}

Treap* remove_balloon(Treap* treap, int pos){
    array<Treap*, 2> split_point1 = split_by_pos(treap, pos);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], 1);

    return merge(split_point1[0], split_point2[1]);
}

Treap* change_balloon(Treap* treap, int pos, int new_color){
    array<Treap*, 2> split_point1 = split_by_pos(treap, pos);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], 1);

    Treap* target = split_point2[0];
    target->val = target->left_color = target->right_color = new_color;

    return merge(split_point1[0], merge(target, split_point2[1]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i = 0; i < n; ++i){
        int balloon;
        cin>>balloon;

        Treap* curr_node = new Treap(balloon);
        treap = merge(treap, curr_node);
    }

    int t;
    cin>>t;

    for(int i = 0; i < t; ++i){
        int type;
        cin>>type;

        if(type == 4){
            cout<<treap_query(treap)<<endl;
            continue;
        }

        int pos;
        cin>>pos;
        --pos;

        if(type == 1){
            treap = remove_balloon(treap, pos);
            continue;
        }

        int color;
        cin>>color;

        if(type == 2){
            treap = insert_balloon(treap, pos, color);
        } else {
            treap = change_balloon(treap, pos, color);
        }
    }
return 0;
}