#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void minimizeScore(int n, int k, vector<int> a)
{
    sort(a.begin(), a.end(), greater<>()); // sort prices descending

    long long score = 0;

    // increase each price as much as possible
    for (int i = 0; i < a.size(); i++)
    {
        if (i % 2 == 0) // Alice takes even items
        {
            score += a[i];
        }
        else // Bob takes odd items
        {
            score -= min(a[i - 1], a[i] + k);
        }
    }

    cout << score << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a;
        for (int j = 0; j < n; j++)
        {
            int ai;
            cin >> ai;

            a.push_back(ai);    
        }

        minimizeScore(n, k, a);
    }
}