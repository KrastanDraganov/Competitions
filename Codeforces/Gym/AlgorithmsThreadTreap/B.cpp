#include<iostream>
#include<array>
#include<random>

#define endl '\n'

using namespace std;

const int INF = 1e9, MAXN = 6e5 + 3, BASE = 31;
mt19937 generator(1948);
uint64_t hash_pow[MAXN];

struct Treap {
    int val, priority;
    int subtree_size;
    uint64_t left_hash, right_hash;
    array<Treap*, 2> kids;

    Treap(int _val) {
        val = _val;
        priority = uniform_int_distribution<int>(1, INF)(generator);
        subtree_size = 1;
        left_hash = right_hash = _val;
        kids = {nullptr, nullptr};
    }
};

Treap* treap = nullptr;

int treap_size(Treap* curr) {
    return curr ? curr->subtree_size : 0;
}

uint64_t treap_left_hash(Treap* curr) {
    return curr ? curr->left_hash : 0;
}

uint64_t treap_right_hash(Treap* curr) {
    return curr ? curr->right_hash : 0;
}

void recover(Treap* curr) {
    if (!curr) {
        return;
    }

    curr->subtree_size = 1;
    for (Treap* kid : curr->kids) {
        curr->subtree_size += treap_size(kid);
    }

    curr->left_hash = treap_left_hash(curr->kids[0]);
    curr->left_hash += hash_pow[treap_size(curr->kids[0])] * curr->val;
    curr->left_hash += hash_pow[treap_size(curr->kids[0]) + 1] * treap_left_hash(curr->kids[1]);

    curr->right_hash = treap_right_hash(curr->kids[1]);
    curr->right_hash += hash_pow[treap_size(curr->kids[1])] * curr->val;
    curr->right_hash += hash_pow[treap_size(curr->kids[1]) + 1] * treap_right_hash(curr->kids[0]);
}

array<Treap*, 2> split_by_pos(Treap* curr, int pos) {
    if (!curr) {
        return {nullptr, nullptr};
    }

    if (pos <= treap_size(curr->kids[0])) {
        array<Treap*, 2> left_split = split_by_pos(curr->kids[0], pos);
        curr->kids[0] = left_split[1];
        recover(curr);
        return {left_split[0], curr};
    } else {
        array<Treap*, 2> right_split = split_by_pos(curr->kids[1], pos - treap_size(curr->kids[0]) - 1);
        curr->kids[1] = right_split[0];
        recover(curr);
        return {curr, right_split[1]};
    }
}

Treap* merge(Treap* l, Treap* r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }

    if (l->priority < r->priority) {
        l->kids[1] = merge(l->kids[1], r);
        recover(l);
        return l;
    } else {
        r->kids[0] = merge(l, r->kids[0]);
        recover(r);
        return r;
    }
}

Treap* add_num(Treap* treap, int pos, int val) {
    array<Treap*, 2> split_point = split_by_pos(treap, pos);

    Treap* new_node = new Treap(val);
    return merge(split_point[0], merge(new_node, split_point[1]));
}

Treap* delete_range(Treap* treap, int l, int r){
    array<Treap*, 2> split_point1 = split_by_pos(treap, l);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], r - l + 1);

    return merge(split_point1[0], split_point2[1]);
}

bool is_palindrome(Treap* &treap, int l, int r) {
    array<Treap*, 2> split_point1 = split_by_pos(treap, l);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[1], r - l + 1);

    bool res = (split_point2[0] and treap_left_hash(split_point2[0]) == treap_right_hash(split_point2[0]));
    treap = merge(split_point1[0], merge(split_point2[0], split_point2[1]));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    hash_pow[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        hash_pow[i] = BASE * hash_pow[i-1];
    }

    int n, q;
    string s;
    cin >> n >> q >> s;

    for (char letter : s) {
        Treap* curr_node = new Treap(letter - 'a');
        treap = merge(treap, curr_node);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 2) {
            char new_letter;
            int pos;
            cin >> new_letter >> pos;
            treap = add_num(treap, pos - 1, new_letter - 'a');
            continue;
        }

        int l, r;
        cin >> l >> r;
        --l;
        --r;

        if (type == 1) {
            treap = delete_range(treap, l, r);
        } else {
            cout << (is_palindrome(treap, l, r) ? "yes" : "no") << endl;
        }
    }
return 0;
}