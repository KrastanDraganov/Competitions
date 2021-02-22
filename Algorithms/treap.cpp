#include<iostream>
#include<random>
#include<chrono>
#include<array>

#define endl '\n'

using namespace std;

const int INF = 1e9+3;
mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
    int val,priority;
    int subtree_size;
    array<Treap*, 2> kids;

    Treap(int _val){
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size=1;
        kids[0] = kids[1] = nullptr;
    }
};

void print_treap(Treap* treap){
    if(!treap){
        cout<<"x ";
        return;
    }

    cout<<treap->val<<" ";
    
    cout<<"l: ";
    print_treap(treap->kids[0]);

    cout<<"r: ";
    print_treap(treap->kids[1]);
}

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

array<Treap*, 2> split_by_num(Treap* curr, int target){
    if(!curr){
        return {nullptr, nullptr};
    }

    if(target <= curr->val){
        array<Treap*, 2> left_split = split_by_num(curr->kids[0], target);
        curr->kids[0] = left_split[1];
        recover(curr);
        return {left_split[0], curr};
    }else{
        array<Treap*, 2> right_split = split_by_num(curr->kids[1], target);
        curr->kids[1] = right_split[0];
        recover(curr);
        return {curr, right_split[1]};
    }
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

Treap* insert_num(Treap* treap, int num){
    array<Treap*, 2> split_point1 = split_by_num(treap, num);
    array<Treap*, 2> split_point2 = split_by_num(split_point1[1], num+1);

    if(split_point2[0]){
        return merge(split_point1[0], merge(split_point2[0], split_point2[1]));
    }

    Treap* new_node = new Treap(num);
    return merge(split_point1[0], merge(new_node, split_point1[1]));
}

Treap* erase_num(Treap* treap, int num){
    array<Treap*, 2> split_point1 = split_by_num(treap, num);
    array<Treap*, 2> split_point2 = split_by_num(split_point1[1], num+1);

    if(!split_point2[0]){
        return merge(split_point1[0], split_point1[1]);
    }

    return merge(split_point1[0], split_point2[1]);
}

int kth_element(Treap* curr, int pos){
    if(!curr){
        return INF;
    }

    if(treap_size(curr->kids[0]) >= pos){
        return kth_element(curr->kids[0], pos);
    }

    if(treap_size(curr->kids[0])+1==pos){
        return curr->val;
    }

    return kth_element(curr->kids[1], pos-treap_size(curr->kids[0])-1);
}

int count_smaller(Treap* curr, int target){
    if(!curr){
        return 0;
    }

    if(target <= curr->val){
        return count_smaller(curr->kids[0], target);
    }

    return 1 + treap_size(curr->kids[0]) + count_smaller(curr->kids[1], target);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Treap* treap = nullptr;

    int q;
    cin>>q;

    while(q--){
        char type;
        int num;
        cin>>type>>num;

        if(type=='I'){
            treap=insert_num(treap, num);
            continue;
        }

        if(type=='D'){
            treap=erase_num(treap, num);
            continue;
        }

        if(type=='C'){
            cout<<count_smaller(treap, num)<<endl;
            continue;
        }

        if(treap_size(treap) < num){
            cout<<"invalid\n";
        }else{
            cout<<kth_element(treap, num)<<endl;
        }
    }
return 0;
}