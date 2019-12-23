#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int used[16384], paths[16384], x1, y1, x2, y2, l, pos = 1, n;
vector <int> v[16384];
queue <int> q;

struct node
{
    int x;
    int y;
};

node points[16384];

int get_pos(int x, int y)
{
    int i;
    for (i=1; i<pos; i++)
        if (points[i].x == x && points[i].y == y) return i;
    return pos;
}

void read()
{
    int i, a, b;
    node p1, p2;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    for (i=1; i<=n; i++)
    {
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        a = get_pos(p1.x, p1.y);
        if (a == pos) points[pos++] = p1;

        b = get_pos(p2.x, p2.y);
        if (b == pos) points[pos++] = p2;

        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void bfs()
{
    int i, sz, a, b, x;
    if (x1 == x2 && y1 == y2)
    {
        cout << 0 << endl;
        return;
    }

    a = get_pos(x1, y1);
    if (a == pos)
    {
        l = 1;
        return;
    }

    b = get_pos(x2, y2);
    if (b == pos)
    {
        l = 1;
        return;
    }

    used[a] = 1;
    q.push(a);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        sz = v[x].size();
        for (i=0; i<sz; i++)
        {
            if (v[x][i] == b)
            {
                cout << (paths[x] + 1)*10 << endl;
                return;
            }
            if (used[v[x][i]] == 0)
            {
                used[v[x][i]] = 1;
                paths[v[x][i]] = paths[x] + 1;
                q.push(v[x][i]);
            }
        }
    }
    l = 1;
}

int main()
{
    read();
    bfs();
    if(l) cout << "no solution" << endl;
    return 0;
}
