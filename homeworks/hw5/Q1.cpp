#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct doll {
    int width, height;
};

bool dollFits(vector<doll>& dolls, int start, int end)
{
    // second doll is taller
    if (dolls[end].height > dolls[start].height)
    {
        for (int i = start + 1; i <= end; i++)
        {
            if (dolls[i].height <= dolls[i - 1].height)
            {
                return false;
            }
        }
    }
    else // first doll is taller
    {
        for (int i = start + 1; i <= end; i++)
        {
            if (dolls[i].height >= dolls[i - 1].height)
            {
                return false;
            }
        }
    }
    return true;
}

bool canNest(const doll& d1, const doll& d2) {
    return (d2.width > d1.width && d2.height > d1.height);
}

// Comparator to sort dolls by width, and then by height
bool compareDolls(const doll& d1, const doll& d2) {
    if (d1.width == d2.width) {
        return d1.height < d2.height;
    }
    return d1.width < d2.width;
}

int minPositiveSlopeLines(vector<doll>& dolls) {
    int n = dolls.size();
    if (n == 0) return 0;

    // Sort the dolls by width and then by height
    sort(dolls.begin(), dolls.end(), compareDolls);

    // DP array to store the minimum number of chains to nest up to the i-th doll
    vector<int> dp(n, n); // Initialize with a large number

    // Base case: Only 1 chain is needed to nest the first doll
    dp[0] = 1;

    // For each doll, calculate the minimum number of chains needed
    for (int i = 1; i < n; ++i) {
        // Try nesting all previous dolls with the current doll
        dp[i] = dp[i - 1] + 1; // Worst case: Start a new chain at doll i
        for (int j = 0; j < i; ++j) {
            if (canNest(dolls[j], dolls[i])) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    // The answer is the minimum number of chains needed to nest all dolls
    return dp[n - 1];
}

int main()
{
    int t;   // number of test cases
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m;  // number of dolls
        cin >> m;

        vector<doll> dolls(m);
        for (int j = 0; j < m; j++)
        {
            int w;  // width of doll
            int h;  // height of doll
            cin >> w >> h;
            dolls[j] = {w, h};
        }

        int result = minPositiveSlopeLines(dolls);
        cout << result << endl;
    }
}