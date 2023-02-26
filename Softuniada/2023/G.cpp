#include <iostream>

#define endl '\n'

using namespace std;

const int MAXN = 5e3 + 3;
const int MAXM = 1e5 + 3;

int from[MAXM], to[MAXM], weight[MAXM];
int parent[MAXN], depth[MAXN];

int find_parent(int currv)
{
    if (currv == parent[currv])
    {
        return currv;
    }

    return parent[currv] = find_parent(parent[currv]);
}

void combine(int v1, int v2)
{
    int root1 = find_parent(v1);
    int root2 = find_parent(v2);

    if (root1 == root2) 
    {
        return;
    }

    if (depth[root2] > depth[root1])
    {
        swap(root1, root2);
    }

    parent[root2] = root1;
    depth[root1] += depth[root2];
}

bool check(int limit, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = i;
        depth[i] = 1;
    }

    for (int i = 0; i < m; ++i)
    {
        if (weight[i] < limit)
        {
            combine(from[i], to[i]);
        }
    }

    return (depth[find_parent(0)] == n);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> from[i] >> to[i] >> weight[i];
    }

    int l = 0, r = 1e5 + 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid, n, m))
        {
            r = mid - 1;
        }
        else 
        {
            l = mid + 1;
        }
    }

    cout << r + 1 << endl;

    return 0;
}