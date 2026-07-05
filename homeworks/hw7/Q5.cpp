class Solution {
void dfs(vector<vector<char>>& grid, int x, int y, int m, int n)
{
    if (x < 0 || y < 0 || x == m || y == n || grid[x][y] == '0')
    {
        return;
    }

    grid[x][y] = '0';
    dfs(grid, x + 1, y, m, n);
    dfs(grid, x - 1, y, m, n);
    dfs(grid, x, y + 1, m, n);
    dfs(grid, x, y - 1, m, n);
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    dfs(grid, i, j, grid.size(), grid[0].size());
                }
            }
        }
        return islands;
    }
};