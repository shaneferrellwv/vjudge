#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

vector<string> findShortestCycle(const unordered_map<string, vector<string>>& graph, const string& start) {
    queue<pair<string, vector<string>>> q;
    unordered_map<string, string> parent; // to store the parent of each node in the path

    // Initialize the queue with the start node and an initial path containing only the start
    q.push({start, {start}});
    parent[start] = "";

    while (!q.empty()) {
        auto [currentNode, path] = q.front();
        q.pop();

        for (const string& neighbor : graph.at(currentNode)) {
            // Check if this neighbor completes a cycle
            if (neighbor == start && path.size() > 2) {
                path.push_back(start); // Complete the cycle
                return path;
            }
            
            // If the neighbor hasn't been visited in this path, add it to the queue
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = currentNode; // Mark the current node as the parent
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push({neighbor, newPath});
            } else if (parent[currentNode] != neighbor) {
                // We've found a cycle but not from an immediate backtracking
                vector<string> cycle = path;
                cycle.push_back(neighbor);
                cycle.push_back(start); // Complete the cycle by adding the start node
                return cycle;
            }
        }
    }
    
    // No cycle found
    return {};
}

int main() {
    // Example usage
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"A", "C", "D"}},
        {"C", {"A", "B", "D"}},
        {"D", {"B", "C"}}
    };
    string startNode = "A";
    
    vector<string> cycle = findShortestCycle(graph, startNode);
    
    if (!cycle.empty()) {
        cout << "Shortest cycle starting from " << startNode << ": ";
        for (const string& node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle found starting from " << startNode << endl;
    }
    
    return 0;
}
