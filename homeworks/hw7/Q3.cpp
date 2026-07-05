#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
    const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    struct PairHash {
        size_t operator()(const pair<int, int>& p) const{
            return hash<long long>()(((long long)p.first << 20) | p.second);
        }
    };

    bool isInBounds(int x, int y)
    {
        return x >= 0 && y >= 0 && x < 1000000 && y < 1000000;
    }

    bool bfs(const vector<vector<int>>& blocked, vector<int> source, vector<int> target)
    {
        unordered_set<pair<int, int>, PairHash> blockedSet;
        for (const auto& b : blocked)
        {
            blockedSet.insert({ b[0], b[1] });
        }

        unordered_set<pair<int, int>, PairHash> visited;
        queue<pair<int, int>> q;
        q.push({ source[0], source[1] });
        visited.insert({source[0], source[1]});
        
        int steps = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == target[0] && y == target[1])
            {
                return true;
            }

            if (steps++ > 20000)
            {
                return true;
            }

            for (const auto& [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;
                auto next = make_pair(nx, ny);

                if (isInBounds(nx, ny) && !blockedSet.count(next) && !visited.count(next))
                {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return false;
    }

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return bfs(blocked, source, target) && bfs(blocked, target, source);
    }
};
