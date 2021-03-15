#include<iostream>

#define endl '\n'

using namespace std;

const int MAXN = 2e5 + 3, MAX_DRINKS = 1e5 + 3;
const uint64_t BASE = 97;

struct Data {
    uint64_t capacity;
    uint64_t lazy;
    bool same;

    Data(){
        capacity = lazy = 0;
        same = true;
    }
};

Data tree[4 * MAXN];
uint64_t hash_pow[MAX_DRINKS];

Data merge_data(Data& l, Data& r) {
    Data res;

    res.same = (l.same & r.same);
    res.same &= (l.capacity == r.capacity);

    res.capacity = (res.same ? l.capacity : 0);
    res.lazy = 0;

    return res;
}

void push_lazy(int ind) {
    if (tree[2 * ind].same) {
        tree[2 * ind].capacity += tree[ind].lazy;
    }
    tree[2 * ind].lazy += tree[ind].lazy;

    if (tree[2 * ind + 1].same) {
        tree[2 * ind + 1].capacity += tree[ind].lazy;
    }
    tree[2 * ind + 1].lazy += tree[ind].lazy;

    tree[ind].lazy = 0;
}

void update_tree(int ind, int tl, int tr, int l, int r, int drink) {
    if (l > tr or r < tl or tl > tr) {
        return;
    }

    if (l == tl and r == tr) {
        uint64_t new_capacity = hash_pow[drink];
        if(tree[ind].same){
            tree[ind].capacity += new_capacity;
        }
        tree[ind].lazy += new_capacity;
        return;
    }

    push_lazy(ind);

    int mid = (tl + tr) / 2;
    update_tree(2 * ind, tl, mid, l, min(mid, r), drink);
    update_tree(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r, drink);

    tree[ind] = merge_data(tree[2 * ind], tree[2 * ind + 1]);
}

// first - type (0 - not same, 1 - same, 2 - out of boundaries)
// second - if same, the value of the given interval
pair<int, uint64_t> query(int ind, int tl, int tr, int l, int r) {
    if (l > tr or r < tl or tl > tr) {
        return {2, 1948};
    }

    if (l == tl and r == tr) {
        return {tree[ind].same, tree[ind].capacity};
    }

    push_lazy(ind);

    int mid = (tl + tr) / 2;
    pair<int, uint64_t> left_child = query(2 * ind, tl, mid, l, min(mid, r));
    pair<int, uint64_t> right_child = query(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r);

    tree[ind] = merge_data(tree[2 * ind], tree[2 * ind + 1]);

    if (left_child.first == 2) {
        return right_child;
    }
    if (right_child.first == 2) {
        return left_child;
    }

    bool res = (left_child.first & right_child.first);
    res &= (left_child.second == right_child.second);

    return {res, left_child.second};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    hash_pow[0] = 1;
    for (int i = 1; i < MAX_DRINKS; ++i) {
        hash_pow[i] = hash_pow[i - 1] * BASE;
    }

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; ++i) {
        int type, l, r;
        cin >> type >> l >> r;
        --l;
        --r;

        if (type == 2) {
            cout << (query(1, 0, n - 1, l, r).first == 1) << endl;
            continue;
        }

        int drink;
        cin >> drink;
        --drink;

        update_tree(1, 0, n - 1, l, r, drink);
    }
return 0;
}
