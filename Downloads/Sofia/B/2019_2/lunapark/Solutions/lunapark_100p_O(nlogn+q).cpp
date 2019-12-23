#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MAX_N = 2e5 + 10;
vector<ll> g[MAX_N], we[MAX_N];
vector<ll> cycle, w, curr, currw;
bool used[MAX_N];
int pos[MAX_N];

void dfs(int x, int p) {
    used[x] = true;
    curr.push_back(x);
    for(int i = 0; i < g[x].size(); i ++) {
        int it = g[x][i];
        if(it != p) {
            if(used[it]) {
                for(int j = curr.size() - 1; ; j --) {
                    cycle.push_back(curr[j]);
                    pos[curr[j]] = curr.size() - 1 - j;
                    if(curr[j] == it) {
                        w.push_back(we[x][i]);
                        return;
                    } else {
                        w.push_back(currw[j - 1]);
                    }
                }
            } else {
                currw.push_back(we[x][i]);
                dfs(it, x);
                currw.pop_back();
                if(cycle.size() != 0) {return;}
            }
        }
    }
    used[x] = false;
    curr.pop_back();
}

ll ansRoot[MAX_N], now, root[MAX_N];

void dfs2(int x, int p, int r) {
    //cout << x << " " << p << endl;
    root[x] = r;
    for(int i = 0; i < g[x].size(); i ++) {
        int nxt = g[x][i];
        if(nxt == p || pos[nxt] != -1) {continue;}
        ansRoot[nxt] = max(ansRoot[x], we[x][i]);
        dfs2(nxt, x, r);
    }
}

struct SegTree {
    ll data[2 * MAX_N];
    void build() {
        for(int i = 0; i < w.size(); i ++) {
            data[i + MAX_N] = w[i];
        }
        for(int i = MAX_N - 1; i > 0; i --) {
            data[i] = max(data[i * 2], data[i * 2 + 1]);
        }
    }
    ll ans(int l, int r) {
        if(l == -1 || r == w.size()) {return 0;}
        l += MAX_N; r += MAX_N + 1;
        ll ret = 0;
        while(l != r) {
            if(l & 1) {ret = max(ret, data[l]); l ++;}
            if(r & 1) {-- r; ret = max(ret, data[r]);}
            l /= 2; r /= 2;
        }
        return ret;
    }
};

SegTree st;
int fake[MAX_N], fakePos[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int a, b, wi;
        cin >> a >> b >> wi;
        g[a].push_back(b);
        g[b].push_back(a);
        we[a].push_back(wi);
        we[b].push_back(wi);
        pos[i + 1] = -1;
        fake[i + 1] = i + 1;
        fakePos[i + 1] = i + 1;
    }
    dfs(1, 0);
    for(int i = 0; i < cycle.size(); i ++) {
        int now = cycle[i];
        if(pos[now] != -1) {
            dfs2(now, -1, now);
        }
    }
    st.build();
    int q;
    cin >> q;
    ll ans = 0;
    for(int i = 0; i < q; i ++) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            a = fakePos[a];
            b = fakePos[b];
            ll ret1 = max(ansRoot[a], ansRoot[b]);
            ll ret2 = ret1;
            a = root[a];
            b = root[b];
            if(pos[a] > pos[b]) {
                swap(a, b);
            }
            ret1 = max(ret1, st.ans(pos[a], pos[b] - 1));
            ret2 = max(ret2, max(st.ans(0, pos[a] - 1), st.ans(pos[b], w.size() - 1)));
            ll curr = 0;
            if(ret1 > ret2) {
                curr = 2 * ret1 + ret2;
            } else {
                curr = 2 * ret2 + ret1;
            }
            ans += curr;
        } else {
            swap(fake[fakePos[a]], fake[fakePos[b]]);
            swap(fakePos[a], fakePos[b]);
        }
    }
    cout << ans << endl;
    return 0;
}