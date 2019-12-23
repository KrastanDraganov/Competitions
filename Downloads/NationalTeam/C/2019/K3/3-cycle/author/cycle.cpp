#include<iostream>
#include <list>
#define NIL -1
using namespace std;

int n,m;
list<int> *adj; // array of adjacency lists

int counter;


// DFS traversal:
// u --> The vertex to be visited next
// visited[] --> keeps tract of visited vertices
// disc[] --> Stores discovery times of visited vertices
// parent[] --> Stores parent vertices in DFS tree

void dfs(int u, bool visited[], int disc[], int low[], int parent[])
{
	static int time = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;

	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u
		if (!visited[v])
		{
			parent[v] = u;
			dfs(v, visited, disc, low, parent);

			// Check if the subtree rooted with v has a
			// connection to one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// If the lowest vertex reachable from subtree
			// under v is below u in DFS tree, then u-v
			// is a bridge
			if (low[v] > disc[u])
            {
			  //cout << u <<" " << v << endl;
			  counter++;
            }
		}
		else if (v != parent[u]) low[u] = min(low[u], disc[v]);
	}
}

int main()
{
    cin >> n >> m;
    adj = new list<int>[n];
    for(int i=1;i<=m;i++)
    {
        int i1,i2;
        cin >> i1 >> i2;
        adj[i1-1].push_back(i2-1);
	    adj[i2-1].push_back(i1-1);
    }

    bool *visited = new bool[n];
	int *disc = new int[n];
	int *low = new int[n];
	int *parent = new int[n];
	for (int i = 0; i < n; i++)
	 {parent[i] = NIL; visited[i] = false;}

	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			dfs(i, visited, disc, low, parent);
    cout << counter << endl;
}
