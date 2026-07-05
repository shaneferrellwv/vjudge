#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;  // number of gemstones
    cin >> n;

    vector<int> gemstones(n);
    for (int i = 0; i < n; i++)
    {
        int c;  // gemstone color
        cin >> c;
        gemstones[i] = c;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (i + 1 == j)
            {
                if (gemstones[i] == gemstones[j])
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 2;
                }
            }
            else
            {
                int temp;
                if (gemstones[i] == gemstones[j])
                {
                    temp = dp[i + 1][j - 1];
                }
                else
                {
                    temp = INT_MAX;
                }

                for (int k = i; k < j; ++k)
                {
                    temp = min(temp, dp[i][k] + dp[k + 1][j]);
                }

                dp[i][j] = temp;
            }
        }
    }

    cout << dp[0][n - 1];
}