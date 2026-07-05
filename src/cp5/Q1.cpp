#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int u, v, w;
};

string shortestPath(vector<edge>& edges, int source, int query)
{
    // Dijkstra's Shortest Path algorithm

    
}

int main()
{
    int n;  // number of nodes
    int m;  // number of edges
    int q;  // number of queries
    int s;  // index of starting node
    
    while (true)
    {
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0)
        {
            return 0;
        }

        int source = s;
        vector<edge> edges(m);
        for (int i = 0; i < m; i++)
        {
            int u, v;   // nodes with a connecting edge
            int w;      // weight of edge
            cin >> u >> v >> w;
            edges[i] = {u, v, w};
        }

        for (int i = 0; i < q; i++)
        {
            int query;  // node to find shortest path to
            cin >> query;
            cout << shortestPath(edges, source, query) << endl;
        }
    }

    return 0;
}