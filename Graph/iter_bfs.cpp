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
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int startNode) {
        // 1. Visited
        unordered_map<int, bool> visited;
        // 2. Queue
        queue<int> q;
        // Start BFS
        q.push(startNode);
        visited[startNode] = true;
        cout << "BFS Traversal: ";
        while (!q.empty()) {
            // 3. Current Node
            int currentNode = q.front();
            q.pop();
            cout << currentNode << " ";
            // 4. Adjacency List
            for (auto neighbor : adj[currentNode]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cout<<"Enter Number of Nodes: ";
    cin>>n;
    int m;
    cout<<"Enter the number of Edges: ";
    cin>>m;
    graph g;
    for (int  i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.PrintEdgeList();
    g.bfs(0);
    
}