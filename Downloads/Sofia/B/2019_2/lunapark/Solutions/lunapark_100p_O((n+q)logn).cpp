#include <bits/stdc++.h>
using namespace std;
int n, q;
vector <pair <int, int> > adj [200005];
bool used [200005];
stack <pair <int, int> > s;
vector <pair <int, int> > cycle;
bool dali = 0;
int dist1 [200005];
int Pos [200005];
int station [200005];
void dfs1 (int a, int par){
    used [a] = 1;
    for (auto i : adj [a]){
        if (i.first == par) continue;
        if (used [i.first]){
            cycle.push_back (i);
            while (s.top ().first != i.first) cycle.push_back (s.top ()), s.pop ();
            dali = 1;
            return;
        }
        s.push (i);
        dfs1 (i.first, a);
        if (dali) return;
        s.pop ();
    }
}
void dfs2 (int a){
    used [a] = 1;
    for (auto i : adj [a]){
        if (used [i.first]) continue;
        dist1 [i.first] = max (dist1 [a], i.second);
        Pos [i.first] = Pos [a];
        dfs2 (i.first);
    }
}/*
long long t [800005];
void build (int l, int r, int pos){
    if (l == r){
        t [pos] = cycle [l].second;
        return;
    }
    int mid = (l + r) >> 1;
    build (l, mid, pos << 1);
    build (mid + 1, r, (pos << 1) + 1);
    t [pos] = max (t [pos << 1], t [(pos << 1) + 1]);
}
long long query (int l, int r, int pos, int ql, int qr){
    if (ql <= l && r <= qr) return t [pos];
    if (ql > r || qr < l) return 0ll;
    int mid = (l + r) >> 1;
    return max (query (l, mid, pos << 1, ql, qr), query (mid + 1, r, (pos << 1) + 1, ql, qr));
}*/
int m;
int rmq [200005][20], Log [2000005];
void build (){
    for (int i = 0; i < m; i ++) rmq [i][0] = cycle [i].second;
    Log [1] = 0;
    for (int k = 1; k < 20; k ++){
        for (int i = (1 << (k - 1)) + 1; i <= (1 << k); i ++) Log [i] = k;
        for (int i = 0; i < m; i ++){
            int j = i + (1 << (k - 1));
            if (j >= m) rmq [i][k] = rmq [i][k - 1];
            else rmq [i][k] = max (rmq [i][k - 1], rmq [j][k - 1]);
        }
    }
}
long long query (int l, int r){
    if (l > r) return 0ll;
    int x = r - l + 1;
    if (x == 1) return rmq [l][0];
    return max (rmq [l][Log [x] - 1], rmq [r - (1 << (Log [x] - 1)) + 1][Log [x] - 1]);
}
int main (){

    ios::sync_with_stdio (false);
    cin.tie (0);

    cin >> n;
    for (int i = 0; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj [u].push_back ({v, w});
        adj [v].push_back ({u, w});
    }
    s.push ({1, 0});
    dfs1 (1, 0);
    for (int i = 1; i <= n; i ++) used [i] = 0, station [i] = i;
    m = cycle.size ();
    for (int i = 0; i < m; i ++){
        used [cycle [i].first] = 1;
        Pos [cycle [i].first] = i;
    }
    for (auto i : cycle) dfs2 (i.first);
    build ();
    cin >> q;
    long long ans = 0ll;
    for (int i = 0; i < q; i ++){
        int type;
        cin >> type;
        if (type == 2){
            int x, y;
            cin >> x >> y;
            swap (station [x], station [y]);
        }
        else{
            int x, y;
            cin >> x >> y;
            x = station [x];
            y = station [y];
            long long max1 = max (dist1 [x], dist1 [y]);
            x = Pos [x];
            y = Pos [y];
            if (x > y) swap (x, y);
            long long p1 = query (x, y - 1);
            long long p2 = max (query (0, x - 1), query (y, m - 1));
            p1 = max (p1, max1);
            p2 = max (p2, max1);
            ans += max (p1, p2) * 2ll + min (p1, p2);
        }
    }
    cout << ans << '\n';

}