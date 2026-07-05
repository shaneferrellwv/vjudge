#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findLISIndices(const vector<long long>& nums)
{
    if (nums.empty())
    {
        return {};
    }

    int n = nums.size();
    vector<long long> tails;
    vector<int> indices(n), parent(n, -1), lisIndices;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
        int idx = distance(tails.begin(), it);

        if (it == tails.end())
        {
            tails.push_back(nums[i]);
        }
        else
        {
            *it = nums[i];
        }

        indices[idx] = i;
        if (idx > 0)
        {
            parent[i] = indices[idx - 1];
        }
    }

    int currentIndex = indices[tails.size() - 1];
    while (currentIndex != -1)
    {
        lisIndices.push_back(currentIndex);
        currentIndex = parent[currentIndex];
    }

    reverse(lisIndices.begin(), lisIndices.end());
    return lisIndices;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<long long> cars(n);
        for (long long i = 0; i < n; i++)
        {
            long long w;
            cin >> w;
            cars[i] = w;
        }

        vector<int> train = findLISIndices(cars);
        cout << train.size() << endl;
        for (int car : train)
        {
            cout << car << " ";
        }
        cout << endl;
    }

    return 0;
}