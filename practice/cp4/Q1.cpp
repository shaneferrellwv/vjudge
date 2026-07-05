#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubsequences(vector<int>& arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);
    vector<int> lds(n, 1);
    int result = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] < arr[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
            if (arr[i] > arr[j])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
        
        result = max(result, lis[i] + lds[i] - 1);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> cars(n);
    for (int i = 0; i < n; i++)
    {
        int w;
        cin >> w;
        cars[i] = w;
    }

    cout << longestSubsequences(cars) << endl;

    return 0;
}