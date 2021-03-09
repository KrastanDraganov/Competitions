#include<iostream>
#include<array>
#include<random>

#define endl '\n'

using namespace std;

const int INF = 1e9;
mt19937 generator(1948);

struct Treap {
    int val, priority;
    int subtree_size;
    array<Treap*, 2> kids;

    Treap(int _val) {
        val = _val;
        priority = uniform_int_distribution<int>(1, INF)(generator);
        subtree_size = 1;
        kids = {nullptr, nullptr};
    }
};

Treap* treap = nullptr;

int treap_size(Treap* curr) {
    return curr ? curr->subtree_size : 0;
}

void recover(Treap* curr) {
    if (!curr) {
        return;
    }

    curr->subtree_size = 1;
    for (Treap* kid : curr->kids) {
        curr->subtree_size += treap_size(kid);
    }
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

Treap* shandomly_ruffle(Treap* treap, int l, int r, int n) {
    if (l >= r) {
        return treap;
    }
    int len = min(r - l, n - r);

    array<Treap*, 2> split_point1 = split_by_pos(treap, r);
    array<Treap*, 2> split_point2 = split_by_pos(split_point1[0], l);

    array<Treap*, 2> interval1 = split_by_pos(split_point2[1], len);
    array<Treap*, 2> interval2 = split_by_pos(split_point1[1], len);

    return merge(split_point2[0], merge(interval2[0], merge(interval1[1], merge(interval1[0], interval2[1]))));
}

void print_treap(Treap* curr) {
    if (!curr) {
        return;
    }

    print_treap(curr->kids[0]);
    cout << curr->val << " ";
    print_treap(curr->kids[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Treap* curr_num = new Treap(i + 1);
        treap = merge(treap, curr_num);
    }

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        treap = shandomly_ruffle(treap, l - 1, r - 1, n);
    }

    print_treap(treap);
    cout<<endl;
return 0;
}