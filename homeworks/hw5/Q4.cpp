#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int workout(int height, vector<int>& distances, int index, vector<vector<int>>& dp)
{
    // base cases:
    if (index < 0)
        return 0;
    if (dp[index][height] != -1)
        return dp[index][height];

    if (distances[index] > height)
    {
        // go up
        dp[index][height] = workout(height - distances[index], distances, index - 1, dp);
        return dp[index][height];
    }
    else
    {
        // go down
        dp[index][height] = ; // idk I give up
    }
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

        vector<vector<int>> dp(M, vector<int>(1000, -1));
        cout << workout(0, distances, M - 1, dp) << endl;
    }
}