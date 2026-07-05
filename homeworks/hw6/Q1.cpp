#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void printDP(const vector<vector<int>>& dp) { for (const auto& row : dp) { for (int val : row) { cout << val << "\t"; // Use \t for tab alignment 
} cout << endl; } }

int main() {

    int h_pack;
    cin >> h_pack;
    vector<int> hotdogs(h_pack);
    int total_dogs = 0;
    for (int i = 0; i < h_pack; i++) {
        cin >> hotdogs[i];
        total_dogs += hotdogs[i];
    }

    int b_pack;
    cin >> b_pack;
    vector<int> buns(b_pack);
    int total_buns = 0;
    for (int i = 0; i < b_pack; i++) {
        cin >> buns[i];
        total_buns += buns[i];
    }

    int max_items = max(total_dogs, total_buns) + 1;
    vector<vector<int>> dp_hotdogs(h_pack + 1, vector<int>(max_items, -1));
    vector<vector<int>> dp_buns(b_pack + 1, vector<int>(max_items, -1));

    // construct 2-D DP array for hot dogs subset-sum
    dp_hotdogs[0][0] = 0;
    for (int i = 1; i < dp_hotdogs.size(); i++) {
        for (int j = 0; j < max_items; j++) {
            if (j >= hotdogs[i - 1] && dp_hotdogs[i - 1][j-hotdogs[i - 1]] > -1 && dp_hotdogs[i-1][j] > -1) {
                dp_hotdogs[i][j] = min(dp_hotdogs[i - 1][j-hotdogs[i - 1]] + 1, dp_hotdogs[i-1][j]);
            }
            else if (j >= hotdogs[i - 1] && dp_hotdogs[i - 1][j-hotdogs[i - 1]] > -1) {
                dp_hotdogs[i][j] = dp_hotdogs[i - 1][j-hotdogs[i - 1]] + 1;
            }
            else {
                dp_hotdogs[i][j] = dp_hotdogs[i-1][j];
            }
        }
    }

    // construct 2-D array for buns subset-sum
    dp_buns[0][0] = 0;
    for (int i = 1; i < dp_buns.size(); i++) {
        for (int j = 0; j < max_items; j++) {
            if (j >= buns[i - 1] && dp_buns[i - 1][j-buns[i - 1]] > -1 && dp_buns[i-1][j] > -1) {
                dp_buns[i][j] = min(dp_buns[i - 1][j-buns[i - 1]] + 1, dp_buns[i-1][j]);
            }
            else if (j >= buns[i - 1] && dp_buns[i - 1][j-buns[i - 1]] > -1) {
                dp_buns[i][j] = dp_buns[i - 1][j-buns[i - 1]] + 1;
            }
            else {
                dp_buns[i][j] = dp_buns[i-1][j];
            }
        }
    }

    // printDP(dp_hotdogs);
    // cout << endl << endl;
    // printDP(dp_buns);
    // cout << endl << endl;

    int min_packages = INT_MAX;
    for (int i = 1; i < dp_hotdogs.size(); i++) {
        for (int j = 1; j < dp_buns.size(); j++) {
            for (int k = 1; k < max_items; k++) {
                if (dp_hotdogs[i][k] > 0 && dp_buns[j][k] > 0) {
                    min_packages = min(min_packages, dp_hotdogs[i][k] + dp_buns[j][k]);
                }
            }
        }
    }

    if (min_packages == INT_MAX) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << min_packages << endl;
    return 0;
}

