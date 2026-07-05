#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    int N;  // number of groups allowed
    int W;  // number of pages allowed
    cin >> N >> W;

    vector<pair<int, int>> groups(N);
    for (int i = 0; i < N; i++)
    {
        int P;  // number of pages in this group
        int V;  // value of this group
        cin >> P >> V;
        groups[i] = {P, V};
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j < W + 1; j++)
        {
            if (groups[i - 1].first <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - groups[i - 1].first] + groups[i - 1].second);
            }
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << *max_element(dp[N].begin(), dp[N].end());

    return 0;
}
