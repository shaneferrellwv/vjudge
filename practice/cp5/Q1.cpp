#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <string>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adjList, int source, vector<int>& dist)
{
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > dist[currentNode])
        {
            continue;
        }

        for (pair<int, int>& neighbor : adjList[currentNode])
        {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (dist[currentNode] + weight < dist[nextNode])
            {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int main()
{
    int n, m, q, s;

    while (true)
    {
        cin >> n >> m >> q >> s;
        if (n == 0 && m == 0 && q == 0 && s == 0)
        {
            break;
        }

        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dijkstra(adjList, s, dist);
        for (int i = 0; i < q; i++)
        {
            int query;
            cin >> query;
            if (dist[query] == INT_MAX)
            {
                cout << "Impossible" << endl;
            }
            else
            {
                cout << dist[query] << endl;
            }
        }
    }

    return 0;
}
