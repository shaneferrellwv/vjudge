#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Global variables
vector<vector<int>> gallery;
vector<vector<vector<int>>> dp;

int closeRooms(int k, int row, int prevClosed)
{
	// Base cases:
	if (k == 0)
		return 0;
	if (row == -1)
		return INT_MAX / 2;

	if (dp[k][row][prevClosed] != -1) {
		return dp[k][row][prevClosed];
	}

	int closeLeft = INT_MAX / 2, closeRight = INT_MAX / 2, closeNone = INT_MAX / 2;

	// Case 1: Close the left room in the current row
	if (prevClosed != 1) {
		closeLeft = closeRooms(k - 1, row - 1, 0) + gallery[row][0];
	}

	// Case 2: Close the right room in the current row
	if (prevClosed != 0) {
		closeRight = closeRooms(k - 1, row - 1, 1) + gallery[row][1];
	}

	// Case 3: Don't close any room in this row
	closeNone = closeRooms(k, row - 1, 2);

	dp[k][row][prevClosed] = min({closeLeft, closeRight, closeNone});
	return dp[k][row][prevClosed];
}

int main()
{
	while (true)
	{
		int N, k;
		cin >> N >> k;
		if (N == 0 && k == 0) break; 

		gallery = vector<vector<int>>(N, vector<int>(2));
		int total = 0;

		for (int i = 0; i < N; i++) {
			cin >> gallery[i][0] >> gallery[i][1];
			total += gallery[i][0] + gallery[i][1];
		}

		dp = vector<vector<vector<int>>>(k + 1, vector<vector<int>>(N, vector<int>(3, -1))); 

		int result = closeRooms(k, N - 1, 2);
		cout << total - result << endl;
	}

	return 0;
}
