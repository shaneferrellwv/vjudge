class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses, 0);

        // find in-degree
        for (const auto& prereq : prerequisites)
        {
            int course = prereq[0];
            int pre = prereq[1];
            edges[pre].push_back(course);
            inDegree[course]++;
        }

        // find starting nodes (in-degree 0)
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // process courses in order
        vector<int> order;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int neighbor : edges[course])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        if (order.size() == numCourses)
        {
            return order;
        }

        return {};
    }
};