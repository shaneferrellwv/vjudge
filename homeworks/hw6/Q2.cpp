#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

// print debug utility
void printDP(const vector<vector<int>>& dp) { for (const auto& row : dp) { for (int val : row) { cout << val << "\t";} cout << endl; } }

void backtrack(const vector<vector<int>> &dp_table, const vector<int> &menu_costs, int i, int j) {
    vector<int> chosen;
    int cost = j;
    while (cost > 0) {
        int item = menu_costs[i-1];
        if (item <= j && dp_table[i-1][j - item] == dp_table[i][j] - 1) {
            chosen.push_back(i);
            i -= 1;
            j -= item;
            cost -= item;
        }
        else if (item <= j && (dp_table[i][j-item] == dp_table[i][j] - 1)) {
            chosen.push_back(i);
            j -= item;
            cost -= item;
        }
        else if (dp_table[i-1][j] == dp_table[i][j])
        {
            i -= 1;
        }
    }

    for (int i = chosen.size() - 1; i >= 0; i--)
    {
        cout << chosen[i] << " ";
    }

    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> menu_costs(n);
    // & O(n)
    for (int i = 0; i < n; i++) {
        cin >> menu_costs[i];
    }

    int m;
    cin >> m;
    vector<int> order_costs(m);
    // & O(m)
    for (int i = 0; i < m; i++) {
        cin >> order_costs[i];
    }

    // construct 2-D DP subset-sum table for every possible total
        // dp_table[i][j]: # of menu items to achieve total j with subset of the first i-th items, 
        //                 -1 if no possible combination of items with subset of the first i-th items that totals j,
        //                 INT_MAX if multiple combinations of items can result in total j
    // & O(n * m)
    int maxOrder = *max_element(order_costs.begin(), order_costs.end());
    vector<vector<int>> dp_table(n + 1, vector<int>(maxOrder + 1, -1));
    dp_table[0][0] = 0;
    for (int i = 1; i < dp_table.size(); i++) {
        for (int j = 0; j < maxOrder + 1; j++) {
            dp_table[i][j] = dp_table[i-1][j];
            if (j > 0 && j >= menu_costs[i - 1] && dp_table[i][j - menu_costs[i - 1]] > -1) {
                if (dp_table[i][j] > -1) {
                    dp_table[i][j] = INT_MAX;
                } else if (dp_table[i][j - menu_costs[i - 1]] == INT_MAX) {
                    dp_table[i][j] = INT_MAX;
                } else {
                    dp_table[i][j] = dp_table[i][j - menu_costs[i - 1]] + 1;
                }
            }
        }
    }

    // print debug
    // cout << endl;
    // printDP(dp_table);
    // cout << endl << endl;

    // loop over orders and calculate if impossible, ambiguous, or what menu items make up order
    // & O(m * s)
    for (int i = 0; i < m; i++) { 
        if (dp_table[n][order_costs[i]] == -1) {
            cout << "Impossible" << endl;
        } else if (dp_table[n][order_costs[i]] == INT_MAX) {
            cout << "Ambiguous" << endl;
        } else {
            // & O(s) where s: maximum order total for the m orders given
            backtrack(dp_table, menu_costs, n, order_costs[i]);
        }
    }

    // & O(n) + O(m) + O(n * m) + O(m * s) = O(m(n + s))

    return 0;
}