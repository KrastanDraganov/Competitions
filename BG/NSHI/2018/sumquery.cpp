// Not solved - wrong idea

#include<iostream>
#include<random>
#include<chrono>
#include<array>

#include "sumquery.h"

#define endl '\n'

using namespace std;

const int INF = 1e9+3;
mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());

struct Treap {
    
     val, priority;
    int subtree_size;
    int sum, query;
    array<Treap*, 2> kids;

    Treap(int _val){
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size = 1;
        sum = query = _val;
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

array<Treap*, 2> split(Treap* curr, long long target){
    if(!curr){
        return {nullptr, nullptr};
    }

    if(target <= curr->val){
        array<Treap*, 2> left_split = split(curr->kids[0], target);
        curr->kids[0] = left_split[1];
        recover(curr);
        return {left_split[0], curr};
    }else{
        array<Treap*, 2> right_split = split(curr->kids[1], target);
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

long long kth_element(Treap* curr, int pos){
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

void init(int q){

}

void add_number(long long num){
    array<Treap*, 2> split_point1 = split(treap, num);
    array<Treap*, 2> split_point2 = split(split_point1[1], num+1);

    Treap* new_node = new Treap(num);
    treap =  merge(split_point1[0], merge(new_node, split_point1[1]));
}

void remove_number(long long num){
    array<Treap*, 2> split_point1 = split(treap, num);
    array<Treap*, 2> split_point2 = split(split_point1[1], num+1);

    treap = merge(split_point1[0], split_point2[1]);
}

