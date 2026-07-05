#include <iostream>
#include <vector>

using namespace std;

long long countIncreasingSubsequence(vector<long long>& cars, long long i, vector<long long>& dp)
{
    // base case
    if (i == 0)
    {
        return 1;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    long long length = 1;
    for (long long prev = 0; prev < i; prev++)
    {
        if (cars[prev] < cars[i])
        {
            length = max(length, countIncreasingSubsequence(cars, prev, dp) + 1);
        }
    }

    dp[i] = length;
    return dp[i];
}

long long longestIncreasingSubsequence(vector<long long>& cars)
{
    vector<long long> memo(cars.size(), -1);
    long long result = 1;
    for (long long i = 1; i < cars.size(); i++)
    {
        result = max(result, countIncreasingSubsequence(cars, i, memo));
    }
    return result;
}

int main()
{
    long long n;  // number of cars
    cin >> n;

    vector<long long> cars(n);
    for (long long i = 0; i < n; i++)
    {
        long long w;  // weight of i-th car
        cin >> w;
        cars[i] = w;
    }

    // find longest increasing subsequence
    cout << longestIncreasingSubsequence(cars) << endl;

    return 0;
}