#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

struct edge {
    int to, t0, P, d;
};

int next_available_time(int current_time, int t0, int P)
{
    if (current_time <= t0)
    {
        return t0;
    }
    if (P == 0)
    {
        return INT_MAX;
    }
    int wait_time = (current_time - t0 + P - 1) / P * P;
    return t0 + wait_time;
}

vector<int> dijkstra(int n, int start, const vector<vector<edge>>& graph)
{
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        auto [time, u] = pq.top();
        pq.pop();

        if (time > dist[u])
        {
            continue;
        }

        for (const edge& edge : graph[u])
        {
            int start_time = next_available_time(time, edge.t0, edge.P);
            if (start_time == INT_MAX)
            {
                continue;
            }
            
            int next_time = start_time + edge.d;
            if (next_time < dist[edge.to])
            {
                dist[edge.to] = next_time;
                pq.push({ next_time, edge.to });
            }
        }
    }
    return dist;
}

int main()
{
    while (true)
    {
        int n, m, q, s;
        cin >> n >> m >> q >> s;

        if (n == 0 && m == 0 && q == 0 && s == 0)
        {
            break;
        }

        vector<vector<edge>> graph(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, t0, P, d;
            cin >> u >> v >> t0 >> P >> d;
            graph[u].push_back({ v, t0, P, d });
        }

        vector<int> dist = dijkstra(n, s, graph);
        for (int i = 0; i < q; ++i)
        {
            int destination;
            cin >> destination;
            if (dist[destination] == INT_MAX)
            {
                cout << "Impossible\n";
            }
            else
            {
                cout << dist[destination] << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
