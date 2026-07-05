#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int, int> countIncreasingSubsequence(vector<int>& cars, int i, vector<pair<int, int>>& dp)
{
    // base case
    if (i == 0)
    {
        return {0, 1};
    }

    // check cache
    if (dp[i].first != -1 && dp[i].second != -1)
    {
        return dp[i];
    }

    int length = 1;
    int start, end;
    for (int prev = 0; prev < i; prev++)
    {
        if (cars[prev] < cars[i])
        {
            pair<int, int> x = countIncreasingSubsequence(cars, prev, dp);
            int y = x.second - x.first + 1;
            if (y > length)
            {
                length = y;
                start = prev;
                end = i;
            }
        }
    }

    // update cache
    dp[i] = {start, end};
    return dp[i];
}

int longestIncreasingSubsequence(vector<int>& cars)
{
    vector<pair<int, int>> memo(cars.size(), {-1, -1});
    int result = 1;
    int start, end;
    for (int i = 1; i < cars.size(); i++)
    {
        pair<int, int> x = countIncreasingSubsequence(cars, i, memo);
        result = max(result, x.second - x.first);
        if (x.second - x.first > result)
        {
            result = x.second - x.first;
            start = x.first;
            end = x.second;
        }
    }
    
    for (int i = start; i < end; i++)
    {
        cout << cars[i];
        if (i != end - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    return result;
}

int main()
{
    int n;  // number of cars
    while (cin >> n)
    {
        vector<int> cars(n);
        for (int i = 0; i < n; i++)
        {
            int w;  // weight of i-th car
            cin >> w;
            cars[i] = w;
        }

        // find longest increasing subsequence
        longestIncreasingSubsequence(cars);
    }

    return 0;
}