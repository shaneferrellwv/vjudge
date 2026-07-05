#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int maxFlow(int n, vector<vector<int>> capacity, vector<vector<int>> flow)
{
    int totalFlow = 0;
    while (true)
    {
        queue<int> q;
        q.push(0);
        vector<int> pred(n, -1);

        while (!q.empty() && pred[n - 1] == -1)
        {
            int current = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (capacity[current][i] > flow[current][i] && i != 0 && pred[i] == -1)
                {
                    pred[i] = current;
                    if (i == n - 1)
                    {
                        break;
                    }
                    q.push(i);
                }
            }
        }

        if (pred[n - 1] == -1)
        {
            break;
        }

        int deltaFlow = INT_MAX;
        for (int i = n - 1; i != 0; i = pred[i])
        {
            deltaFlow = min(deltaFlow, capacity[pred[i]][i] - flow[pred[i]][i]);
        }

        for (int i = n - 1; i != 0; i = pred[i])
        {
            flow[pred[i]][i] += deltaFlow;
            flow[i][pred[i]] -= deltaFlow;
        }

        totalFlow = totalFlow + deltaFlow;
    }

    return totalFlow;
}



int main()
{
    int n;
    cin >> n;

    vector<int> rooms(n, 0);
    for (int i = 0; i < n; i ++)
    {
        cin >> rooms[i];
    }
    
    sort(rooms.begin(), rooms.end());
    vector<vector<int>> graph(n, vector<int>(n, 0));    
    vector<vector<int>> flow(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
            {
                continue;
            }

            int factor = gcd(rooms[i], rooms[j]);
            if (factor > 1) 
            {
                graph[i][j] = factor;
            }
        }
    }

    cout << maxFlow(n, graph, flow) << endl;

    return 0;
}