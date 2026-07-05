class Solution {
public:
    bool dfs(string& s, string& p, int i, int j, vector<vector<int>>& dp)
    {
        if (i >= s.length() && j >= p.length())
        {
            return true;
        }
        if (j >= p.size())
        {
            return false;
        }

        // memoization
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        bool result = false;
        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');

        if (j + 1 < p.length() && p[j + 1] == '*')
        {
            result = (match && dfs(s, p, i + 1, j, dp)) || dfs(s, p, i, j + 2, dp);
        }
        else if (match)
        {
            result = dfs(s, p, i+1, j+1, dp);
        }

        dp[i][j] = result;
        return result;
    }

    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length(), -1));
        return dfs(s, p, 0, 0, dp);
    }
};