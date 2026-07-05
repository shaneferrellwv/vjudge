#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<string>& sky, int x, int y, int m, int n)
{
    if (x < 0 || y < 0 || x == m || y == n || sky[x][y] != '-')
    {
        return;
    }

    sky[x][y] = '#';
    dfs(sky, x + 1, y, m, n);
    dfs(sky, x - 1, y, m, n);
    dfs(sky, x, y + 1, m, n);
    dfs(sky, x, y - 1, m, n);
}

int countStars(vector<string>& sky, int m, int n)
{
    int starCount = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (sky[i][j] == '-') 
            {
                starCount++;
                dfs(sky, i, j, m, n);
            }
        }
    }
    return starCount;
}

int main() {
    int t = 1;
    int m, n;
    while (cin >> m >> n)
    {
        vector<string> sky(m);

        for (int i = 0; i < m; ++i)
        {
            cin >> sky[i];
        }

        int result = countStars(sky, m, n);
        cout << "Case " << t++ << ": " << result << endl;
    }

    return 0;
}
