#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    vector<vector<int>> edges(f, vector<int>());
    for (int i = 0; i < f; i++)
    {
        if (i + u < f && u)
        {
            edges[i].push_back(i + u);
        }
        if (i - d >= 0 && d)
        {
            edges[i].push_back(i - d);
        }
    }

    vector<int> buttons(f, INT_MIN);
    queue<int> q;

    buttons[s - 1] = 0;
    q.push(s - 1);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (int i : edges[top])
        {
            if (buttons[i] == INT_MIN || buttons[i] > buttons[top] + 1)
            {
                buttons[i] = buttons[top] + 1;
                q.push(i);
            }
        }
    }

    if (buttons[g - 1] == INT_MIN)
    {
        cout << "use the stairs" << endl;
    }
    else
    {
        cout << buttons[g - 1] << endl;
    }

    return 0;
}