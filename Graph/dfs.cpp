#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void PrintEdgeList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int node, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int startNode)
    {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal: ";
        dfsHelper(startNode, visited);
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter Number of Nodes: ";
    cin >> n;
    int m;
    cout << "Enter the number of Edges: ";
    cin >> m;
    graph g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.PrintEdgeList();
    g.dfs(0);
}
