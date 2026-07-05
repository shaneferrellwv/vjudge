#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

static vector<pair<string, int>> paths;
static int minHeight = INT_MAX;

string backtrack(vector<pair<string, int>>& paths, vector<int>& distances)
{
    if (paths.size() == 0)
    {
        return "IMPOSSIBLE";
    }

    for (pair<string, int>& path : paths)
    {
        if (path.second == minHeight)
        {
            return path.first;
        }
    }
}

// returns minimum building height of specified path if it leads back to ground level
// otherwise returns -1
int findPatterns(vector<int>& distances, int reps, int i, int height, int maxHeight, string path)
{
    // base case: workout finished
    if (i == reps)
    {
        if (height != 0)
        {
            return -1;
        }
        else
        {
            paths.push_back({path, maxHeight});
            minHeight = maxHeight;
            return maxHeight;
        }
    }

    if (height - distances[i] >= 0)
    {
        findPatterns(distances, reps, i + 1, height - distances[i], max(maxHeight, height - distances[i]), path + 'D');
    }
    if (height + distances[i] < minHeight)
    {
        findPatterns(distances, reps, i + 1, height + distances[i], max(maxHeight, height + distances[i]), path + 'U');
    }
    return -1;
}

int main()
{
    int N;  // number of tests
    cin >> N;

    for (int n = 0; n < N; n++)
    {
        int M;  // number of climbing distances
        cin >> M;

        vector<int> distances(M);
        for (int m = 0; m < M; m++)
        {
            int d; // distance to climb (d_i)
            cin >> d;
            distances[m] = d;
        }

        findPatterns(distances, M, 0, 0, 0, "");
        cout << backtrack(paths, distances) << endl;
        paths = {};
        minHeight = INT_MAX;
    }
}