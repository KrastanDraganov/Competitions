#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

const int MAXN = 5e3 + 3;

int64_t dist[MAXN];
int parent[MAXN];

vector<int> find_min_dist(vector<vector<pair<int, int64_t>>>& graph, int n)
{
    for (int i = 0; i < n; ++i)
    {
        dist[i] = -1ll;
        parent[i] = -1;
    }
    
    dist[0] = 0;
    parent[0] = -1;
    
    queue<int> spfa;
    vector<bool> in_queue(n, false);

    spfa.push(0);
    in_queue[0] = true;

    while (!spfa.empty())
    {
        int currv = spfa.front();
        spfa.pop();
        in_queue[currv] = false;

        for (auto &edge : graph[currv])
        {
            int nextv = edge.first;
            int64_t weight = edge.second;

            int64_t curr_dist = dist[currv] + weight;

            if (dist[nextv] == -1 or curr_dist < dist[nextv] or (curr_dist == dist[nextv] and currv < parent[nextv]))
            {
                dist[nextv] = curr_dist;
                parent[nextv] = currv;

                if (!in_queue[nextv])
                {
                    spfa.push(nextv);
                    in_queue[nextv] = true;
                }
            }  
        }
    }

    vector<int> path;
    
    int currv = n - 1;
    while (currv != -1)
    {
        path.push_back(currv);
        currv = parent[currv];
    }

    reverse(path.begin(), path.end());

    return path;
}

vector<int> find_result_path(int currv, vector<vector<bool>>& blocked, int n)
{
    vector<int> result;

    result.push_back(0);
    result.push_back(currv);

    while (currv != n - 1)
    {
        for (int nextv = 0; nextv < n; ++nextv)
        {
            if (blocked[currv][nextv])
            {
                blocked[currv][nextv] = false;
                result.push_back(nextv);
                currv = nextv;
                break;
            }
        }
    }

    return result;
}

void print_path(vector<int>& path)
{
    int n = (int) path.size();

    cout << path[0];
    for (int i = 1; i < n; ++i)
    {
        cout << " -> " << path[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int64_t>>> graph(n);
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        int64_t weight;

        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    vector<int> path1 = find_min_dist(graph, n);

    vector<vector<bool>> blocked(n, vector<bool>(n, false));
    for (int i = 1; i < (int) path1.size(); ++i)
    {
        int from = path1[i - 1];
        int to = path1[i];

        blocked[from][to] = true;
    }

    vector<vector<pair<int, int64_t>>> new_graph(n);
    for (int currv = 0; currv < n; ++currv)
    {
        for (auto &edge : graph[currv]) 
        {
            int nextv = edge.first;
            int64_t curr_weight = edge.second;

            if (blocked[nextv][currv])
            {
                new_graph[currv].push_back({nextv, 0ll});
            } 
            else if (!blocked[currv][nextv])
            {
                int64_t new_weight = curr_weight + dist[currv] - dist[nextv];
                new_graph[currv].push_back({nextv, new_weight});
            }
        }
    }

    vector<int> path2 = find_min_dist(new_graph, n);

    for (int i = 1; i < (int) path2.size(); ++i)
    {
        int from = path2[i - 1];
        int to = path2[i];

        if (blocked[to][from])
        {
            blocked[from][to] = blocked[to][from] = false;
        }
        else
        {
            blocked[from][to] = true;
        }
    }

    vector<int> result1, result2;
    for (int nextv = 1; nextv < n; ++nextv)
    {
        if (blocked[0][nextv])
        {
            if (result1.empty())
            {
                result1 = find_result_path(nextv, blocked, n);
            }
            else
            {
                result2 = find_result_path(nextv, blocked, n);
            }
        }
    }

    print_path(result1);
    print_path(result2);

    return 0;
}