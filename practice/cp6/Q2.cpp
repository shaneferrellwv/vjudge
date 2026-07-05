#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

vector<int> findShortestCycle(const vector<vector<int>>& adjList, int start, int n)
{
    vector<int> parent(n, -1);
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    for (int neighbor : adjList[start])
    {
        dist[neighbor] = 1;
        q.push(neighbor);
        parent[neighbor] = start;
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : adjList[curr])
        {
            if (dist[curr] + 1 < dist[next])
            {
                dist[next] = dist[curr] + 1;
                parent[next] = curr;
                q.push(next);
            }
        }
    }

    vector<int> cycle;
    if (dist[start] != INT_MAX)
    {
        int curr = parent[start];
        parent[start] = -1;
        while (curr != start)
        {
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(start);
    }

    reverse(cycle.begin(), cycle.end());
    return cycle;
}

int main() {
    int n;
    cin >> n;

    vector<string> indexToName;
    unordered_map<string, int> nameToIndex;
    for (int i = 0; i < n; i++)
    {
        string fileName;
        cin >> fileName;
        indexToName.push_back(fileName);
        nameToIndex.emplace(fileName, i);
    }

    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        string fileName;
        cin >> fileName;

        int k;
        cin >> k;
        cin.ignore();

        for (int j = 0; j < k; j++)
        {
            string line;
            getline(cin, line);
            stringstream ss(line);

            string dependency;
            while (ss >> dependency)
            {
                while (!dependency.empty() && dependency.front() == ',')
                {
                    dependency.erase(dependency.begin());
                }

                while (!dependency.empty() && dependency.back() == ',')
                {
                    dependency.pop_back();
                }

                if (nameToIndex.find(dependency) != nameToIndex.end())
                {
                    adjList[nameToIndex[fileName]].push_back(nameToIndex[dependency]);
                }
            }
        }
    }

    vector<int> bestCycle;
    for (int i = 0; i < n; i++)
    {
        vector<int> shortestCycle = findShortestCycle(adjList, i, n);
        if (!shortestCycle.empty())
        {
            if (bestCycle.empty() || shortestCycle.size() < bestCycle.size())
            {
                bestCycle = shortestCycle;
            }
        }
    }

    if (!bestCycle.empty())
    {
        for (int index : bestCycle)
        {
            cout << indexToName[index] << " ";
        }
    }
    else
    {
        cout << "SHIP IT" << endl;
    }

    return 0;
}
