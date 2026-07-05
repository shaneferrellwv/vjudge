class Solution {
public:
    int dfs(vector<vector<char>>& seats, vector<vector<int>>& dp, int row, int prevMask, int m, int n)
    {
        if (row == m)
        {
            return 0;
        }
        if (dp[row][prevMask] != -1)
        {
            return dp[row][prevMask];
        }

        int maxMask = 1 << n;
        int res = 0;
        for (int mask = 0; mask < maxMask; ++mask)
        {
            bool isValid = true;
            int count = 0;
            for (int j = 0; j < n; ++j)
            {
                if (mask & (1 << j))
                {
                    if (seats[row][j] == '#')
                    {
                        isValid = false;
                        break;
                    }
                    if (j > 0 && (mask & (1 << (j - 1))))
                    {
                        isValid = false;
                        break;
                    }
                    if (j < n - 1 && (mask & (1 << (j + 1))))
                    {
                        isValid = false;
                        break;
                    }
                    if (j > 0 && (prevMask & (1 << (j - 1))))
                    {
                        isValid = false;
                        break;
                    }
                    if (j < n - 1 && (prevMask & (1 << (j + 1))))
                    {
                        isValid = false;
                        break;
                    }
                    count++;
                }
            }

            if (isValid)
            {
                res = max(res, count + dfs(seats, dp, row + 1, mask, m, n));
            }
        }

        dp[row][prevMask] = res;
        return res;
    }

    int maxStudents(vector<vector<char>>& seats)
    {
        int m = seats.size(), n = seats[0].size();
        int maxMask = 1 << n;
        vector<vector<int>> dp(m + 1, vector<int>(maxMask, -1));
        return dfs(seats, dp, 0, 0, m, n);
    }
};