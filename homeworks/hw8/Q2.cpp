#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int n, m, l;
        cin >> n >> m >> l;
        
        vector<vector<int>> adjList(n + 1);
        
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
        }
        
        queue<int> queue;
        vector<bool> fell(n + 1, false);
        for (int i = 0; i < l; i++)
        {
            int z;
            cin >> z;
            if (!fell[z])
            {
                queue.push(z);
                fell[z] = true;
            }
        }
        
        int total = 0;
        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();
            total++;
            for (int neighbor : adjList[current])
            {
                if (!fell[neighbor])
                {
                    queue.push(neighbor);
                    fell[neighbor] = true;
                }
            }
        }
        
        cout << total << endl;
    }

    return 0;
}
