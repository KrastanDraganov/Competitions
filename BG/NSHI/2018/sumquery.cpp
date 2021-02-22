#include<iostream>
#include<random>
#include<chrono>
#include<array>

#include "sumquery.h"

#define endl '\n'

using namespace std;

const int INF = 1e9+3, MOD = 1e9+7;
mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());

void add_mod(int& x, int y){
    x += y;
    if(x >= MOD) {
        x -= MOD;
    }
}

int mul_mod(int x, int y){
    return 1ll * x * y % MOD;
}

struct Treap {
    long long val;
    int priority;
    int subtree_size;
    int sum, query;
    array<Treap*, 2> kids;

    Treap(long long _val){
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size = 1;
        sum = query = _val % MOD;
        kids[0] = kids[1] = nullptr;
    }
};

Treap* treap = nullptr;

int treap_size(Treap* curr){
    return curr ? curr->subtree_size : 0;
}

int treap_sum(Treap* curr){
    return curr ? curr->sum : 0;
}

int treap_query(Treap* curr){
    return curr ? curr->query : 0;
}

void recover(Treap* curr){
    if(!curr){
        return;
    }

    curr->query = curr->val % MOD;
    int pos = treap_size(curr->kids[0]) + 1;
    curr->query = mul_mod(curr->query, pos);
    add_mod(curr->query, treap_query(curr->kids[0]));
    add_mod(curr->query, treap_query(curr->kids[1]));
    add_mod(curr->query, mul_mod(pos, treap_sum(curr->kids[1])));

    curr->subtree_size = 1;
    curr->sum = curr->val % MOD;

    for(Treap* kid : curr->kids){
        curr->subtree_size += treap_size(kid);
        add_mod(curr->sum, treap_sum(kid));
    }
}

array<Treap*, 2> split_by_num(Treap* curr, long long target){
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

void init(int q){

}

void add_number(long long num){
    array<Treap*, 2> split_point = split_by_num(treap, num);

    Treap* new_node = new Treap(num);
    treap = merge(split_point[0], merge(new_node, split_point[1]));
}

void remove_number(long long num){
    array<Treap*, 2> split_point1 = split_by_num(treap, num);
    array<Treap*, 2> split_point2 = split_by_num(split_point1[1], num+1);

    treap = merge(split_point1[0], split_point2[1]);
}

int sum_query(int l, int r){
    array<Treap*, 2> split_point1 = split_by_pos(treap, l);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], r-l+1);

    Treap* interval = split_point2[0];
    int res = interval->query;

    treap = merge(split_point1[0], merge(interval, split_point2[1]));

    return res;
}