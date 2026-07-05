#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isConnected(int p, vector<vector<int>>& graph, int a, int b)
{
    vector<bool> visited(p, false);
    queue<int> q;
    int start = 0;
    
    for (int i = 0; i < p; i++)
    {
        if (!graph[i].empty())
        {
            start = i;
            break;
        }
    }
    
    q.push(start);
    visited[start] = true;
    int visitedCount = 1;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (int neighbor : graph[node])
        {
            if ((node == a && neighbor == b) || (node == b && neighbor == a))
            {
                continue;
            }
            else if (!visited[neighbor])
            {
                visited[neighbor] = true;
                visitedCount++;
                q.push(neighbor);
            }
        }
    }
    
    return visitedCount == p;
}

int main() {
    while (true)
    {
        int p, c;
        cin >> p >> c;
        
        if (p == 0 && c == 0)
        {
            return 0;
        }
        
        vector<vector<int>> graph(p);
        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        bool criticalEdgeFound = false;
        for (int i = 0; i < p && !criticalEdgeFound; i++)
        {
            for (int j : graph[i])
            {
                if (i < j)
                {
                    if (!isConnected(p, graph, i, j))
                    {
                        criticalEdgeFound = true;
                        break;
                    }
                }
            }
        }
        cout << (criticalEdgeFound ? "Yes" : "No") << endl;
    }
    
    return 0;
}
