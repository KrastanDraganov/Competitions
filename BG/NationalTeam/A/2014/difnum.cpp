// Not solved - 0 points, wrong answer

#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<array>
#include<random>

#define endl '\n'

using namespace std;

const int MAXN = 5e4 + 3, INF = 1e9;
mt19937 generator(1948);

struct Treap {
    int val, priority;
    int subtree_size;
    array<Treap*, 2> kids;
    
    Treap(int _val) {
        val = _val;
        priority = uniform_int_distribution<int>(0, INF)(generator);
        subtree_size = 1;
        kids = {nullptr, nullptr};
    }
};

int nums[MAXN], nearest_left[MAXN];
map<int, set<int>> positions;
Treap* tree[4 * MAXN];

void print_treap(Treap* curr) {
    if (!curr) {
        return;
    }

    cout << curr->val << " ";
    
    cout << "l: ";
    print_treap(curr->kids[0]);

    cout << "r: ";
    print_treap(curr->kids[1]);
}

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

Treap* merge_treap(Treap* l, Treap *r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }

    if (l->priority < r->priority) {
        l->kids[1] = merge_treap(l->kids[1], r);
        recover(l);
        return l;
    } else {
        r->kids[0] = merge_treap(l, r->kids[0]);
        recover(r);
        return r;
    }
}

array<Treap*, 2> split(Treap* curr, int target) {
    if (!curr) {
        return {nullptr, nullptr};
    }

    if (curr->val < target) {
        array<Treap*, 2> right_split = split(curr->kids[1], target);
        curr->kids[1] = right_split[0];
        recover(curr);
        return {curr, right_split[1]};
    } else {
        array<Treap*, 2> left_split = split(curr->kids[0], target);
        curr->kids[0] = left_split[1];
        recover(curr);
        return {left_split[0], curr};
    }
}

Treap* insert_num_treap(Treap* treap, int num) {
    array<Treap*, 2> split_point1 = split(treap, num);
    
    Treap* new_node = new Treap(num);
    return merge_treap(split_point1[0], merge_treap(new_node, split_point1[1]));
}

Treap* erase_num_treap(Treap* treap, int num) {
    array<Treap*, 2> split_point1 = split(treap, num);
    array<Treap*, 2> split_point2 = split(split_point1[1], num + 1);

    return merge_treap(split_point1[0], split_point2[1]);
}

int count_smaller_treap(Treap* treap, int target) {
    if (!treap) {
        return 0;
    }

    if (treap->val >= target) {
        return count_smaller_treap(treap->kids[0], target);
    }

    return treap_size(treap->kids[0]) + 1 + count_smaller_treap(treap->kids[1], target);
}

void build_tree(int ind, int tl, int tr) {
    if (tl == tr) {
        tree[ind] = new Treap(nearest_left[tl]);
        return;
    }

    int mid = (tl + tr) / 2;
    build_tree(2 * ind, tl, mid);
    build_tree(2 * ind + 1, mid + 1, tr);

    tree[ind] = merge_treap(tree[2 * ind], tree[2 * ind + 1]);
}

void tree_update_pos(int ind, int tl, int tr, int pos, int new_value) {
    tree[ind] = erase_num_treap(tree[ind], nearest_left[pos]);
    tree[ind] = insert_num_treap(tree[ind], new_value);

    if (tl == tr) {
        nearest_left[pos] = new_value;
        return;
    }

    int mid = (tl + tr) / 2;
    if (pos <= mid) {
        tree_update_pos(2 * ind, tl, mid, pos, new_value);
    } else {
        tree_update_pos(2 * ind + 1, mid + 1, tr, pos, new_value);
    }
}

int tree_query(int ind, int tl, int tr, int l, int r, int limit) {
    if (l > r or l > tr or r < tl) {
        return 0;
    }

    if (l == tl and r == tr) {
        return count_smaller_treap(tree[ind], limit);
    }

    int mid = (tl + tr) / 2;
    return tree_query(2 * ind, tl, mid, l, min(r, mid), limit)
         + tree_query(2 * ind + 1, mid + 1, tr, max(l, mid + 1), r, limit);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];

        set<int> &curr = positions[nums[i]];
        nearest_left[i] = (curr.empty() ? -1 : *curr.rbegin());
        tree_update_pos(1, 0, n - 1, i, nearest_left[i]);

        curr.insert(i);
    }

    print_treap(tree[1]);

    int q, m;
    cin >> q >> m;

    int p = 0;
    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 0) {
            int l, r;
            cin >> l >> r;
            l ^= p;
            r ^= p;

            int res = tree_query(1, 0, n - 1, l, r, l);
            cout << res << endl;

            p ^= res;
            continue;
        }

        int pos, new_value;
        cin >> pos >> new_value;
        pos ^= p;
        new_value ^= p;

        set<int> &prev_num = positions[nums[pos]];
        set<int> &new_num = positions[new_value];

        auto it = prev_num.lower_bound(pos);
        ++it;
        if (it != prev_num.end()) {
            tree_update_pos(1, 0, n - 1, *it, nearest_left[pos]);
        }

        it = new_num.upper_bound(pos);
        if (it != new_num.end()) {
            tree_update_pos(1, 0, n - 1, *it, pos);
        }

        if (it != new_num.begin()) {
            --it;
            tree_update_pos(1, 0, n - 1, pos, *it);
        } else {
            tree_update_pos(1, 0, n - 1, pos, -1);
        }

        nums[pos] = new_value;
        prev_num.erase(pos);
        new_num.insert(pos);
    }
return 0;
}