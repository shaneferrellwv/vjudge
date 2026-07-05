#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findHamiltonianPath(vector<vector<bool>>& adj, unordered_set<int>& visited, int source, int N)
{
    vector<int> children;
    for (int i = 0; i < N; i++)
    {
        if (adj[source][i])
        {
            children.push_back(i);
        }
    }

    if (children.empty() && N == 1)
    {
        return {source};
    }
}

int main()
{
    int N;  // number of nodes
    int K;  // number of edges
    cin >> N >> K;

    vector<pair<int, int>> edges(K);
    for (int i = 0; i < K; i++)
    {
        int a, b;   // nodes connected by this edge
        cin >> a >> b;
        edges[i] = { a, b };
    }

    // construct directed adjacency matrix
    vector<vector<bool>> adj(N, vector<bool>(N, false));
    for (int i = 0; i < K; i++)
    {
        adj[edges[i].first][edges[i].second] = true;
    }

    // find node with in-degree 0
    for (int i = 0; i < N; i++)
    {
        bool possibleSource = true;
        for (int j = 0; j < N; j++)
        {
            if (adj[j][i])
            {
                possibleSource = false;
                break;
            }
        }

        if (possibleSource)
        {
            unordered_set<int> visited = {};
            findHamiltonianPath(adj, visited, i, N);
        }
    }

    return 0;
}