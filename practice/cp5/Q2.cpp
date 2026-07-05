#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> adj(N);
    vector<int> in_degree(N, 0);
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        if (q.size() > 1)
        {
            cout << "back to the lab" << endl;
            return 0;
        }

        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj[node])
        {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    if (order.size() != N)
    {
        cout << "back to the lab" << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
