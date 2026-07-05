class Solution {
    void findBridges(vector<vector<int>>& graph, vector<int>& time, vector<int>& lowestTime,
                     int node, int parent, int currentTime, vector<vector<int>>& critical, vector<bool>& visited)
    {
        visited[node] = true;
        time[node] = currentTime;
        lowestTime[node] = currentTime;

        for(auto newNode : graph[node])
        {
            if(newNode != parent)
            {
                if(visited[newNode] == false)
                {
                    findBridges(graph, time, lowestTime,
                                newNode, node, currentTime + 1, critical, visited);
                    lowestTime[node] = min(lowestTime[node], lowestTime[newNode]);

                    if(lowestTime[newNode] > time[node])
                    {
                        critical.push_back({ node, newNode });
                    }
                }
                else
                {
                    lowestTime[node] = min(lowestTime[node], lowestTime[newNode]);
                }
            }
        }  
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> time(n, 0);
        vector<int> lowestTime(n, 0);
        vector<vector<int>> graph(n + 1);

        for(auto edge : connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> critical;
        vector<bool> visited(n, false);
        findBridges(graph, time, lowestTime, 0, 0, 1, critical, visited);
        return critical;
    }
};