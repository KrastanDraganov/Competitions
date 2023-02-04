// Not solved - Wrong Answer, 21 points

#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 3;
const int MAXM = 1e6 + 3;

struct Edge
{
    int to, type, idx;

    Edge(int _to, int _type, int _idx)
    {
        to = _to;
        type = _type;
        idx = _idx;
    }
};

struct Result
{
    int edge, from, to;

    Result(int _edge, int _from, int _to)
    {
        edge = _edge;
        from = _from;
        to = _to;
    }
};

vector<Edge> graph[MAXN];
int in_degree[MAXN];
int is_edge_visited[MAXM];
int edge_idx[MAXN];

vector<pair<int, int>> cycles[MAXN];
bool are_cycles_cleared[MAXN];

bool brute_force(int currv, int counter, int m, vector<int>& res)
{
    if (counter == m and currv == 0)
    {
        cout << (int) res.size() << endl;
        for (int edge : res)
        {
            cout << edge + 1 << " ";
        }
        cout << endl;

        return true;
    }

    for (Edge &edge : graph[currv])
    {
        if (is_edge_visited[edge.idx] == 0)
        {
            is_edge_visited[edge.idx] = 1;
            res.push_back(edge.idx);

            if (brute_force(edge.to, counter + 1, m, res))
            {
                return true;
            }

            is_edge_visited[edge.idx] = 0;
            res.pop_back();
        }
        else if (edge.type == 2 and is_edge_visited[edge.idx] == 1)
        {
            is_edge_visited[edge.idx] = 2;
            res.push_back(edge.idx);

            if (brute_force(edge.to, counter, m, res))
            {
                return true;
            }

            is_edge_visited[edge.idx] = 1;
            res.pop_back();
        }
    }

    return false;
}

void dfs(int currv, vector<Result>& res)
{
    for (int &i = edge_idx[currv]; i < (int) graph[currv].size(); ++i)
    {
        Edge &edge = graph[currv][i];

        if (is_edge_visited[edge.idx] == 0)
        {
            is_edge_visited[edge.idx] = 1;
            res.push_back(Result(edge.idx, currv, edge.to));

            dfs(edge.to, res);
        }
    }
}

void find_path(int n, int m, bool is_brute_force)
{
    if (is_brute_force)
    {
        vector<int> test;

        if (!brute_force(0, 0, m, test))
        {
            cout << -1 << endl;
        }

        return;
    }

    for (int i = 0; i < n; ++i) {
        if (in_degree[i] % 2 == 1)
        {
            cout << -1 << endl;
            return;
        }
    }

    vector<Result> res;
    dfs(0, res);

    int last_one = -1;
    for (int i = 0; i < (int) res.size(); ++i)
    {
        if (res[i].to == 0)
        {
            last_one = i;
        }
    }

    pair<int, int> cycle_start = {-1, -1};
    for (int i = last_one + 1; i < (int) res.size(); ++i)
    {
        if (cycle_start.first == -1)
        {
            cycle_start = {res[i].from, i};
        }
        else if (cycle_start.first == res[i].to)
        {
            cycles[cycle_start.first].push_back({cycle_start.second, i});
            cycle_start = {-1, -1};
        }
    }

    cout << (int) res.size() << endl;
    for (int i = 0; i <= last_one; ++i) {
        cout << res[i].edge + 1 << " ";

        if (!are_cycles_cleared[res[i].to])
        {
            for (pair<int, int> interval : cycles[res[i].to])
            {
                for (int j = interval.first; j <= interval.second; ++j)
                {
                    cout << res[j].edge + 1 << " ";
                }
            }

            are_cycles_cleared[res[i].to] = true;
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int from, to, type;
        cin >> from >> to >> type;

        --from;
        --to;

        graph[from].push_back(Edge(to, type, i));
        graph[to].push_back(Edge(from, type, i));

        ++in_degree[from];
        ++in_degree[to];
    }

    find_path(n, m, false);

    return 0;
}