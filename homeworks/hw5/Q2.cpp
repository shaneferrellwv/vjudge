#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;  // number of test cases
    cin >> t;

    for (int T = 0; T < t; T++)
    {
        int n;          // number of cells
        int p;          // first cell that ball should bounce on
        int k;          // how many cells the ball moves on each bounce
        string pattern; // which cells have a platform
        int x;          // cost of adding platform
        int y;          // cost to remove the first cell and reorder
        cin >> n >> p >> k >> pattern >> x >> y;
        p--;            

        int result = INT_MAX;
        vector<int> platforms(n);
        for (int i = n - 1; i >= 0; i--)
        {
            platforms[i] = pattern[i] == '0';

            if (i + k < n)
            {
                platforms[i] += platforms[i + k];
            }

            if (i >= p)
            {
                result = min(result, (i - p) * y + platforms[i] * x);
            }
        }

        cout << result << endl;
    }
}