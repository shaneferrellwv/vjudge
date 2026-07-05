#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void build(vector<int>& rainfall, vector<int>& segtree, int l, int r, int i)
{
    if (l == r)
    {
        segtree[i] = rainfall[l];
    }
    else
    {
        int mid = (r - l) / 2 + l;
        build(rainfall, segtree, l, mid, 2 * i + 1);
        build(rainfall, segtree, mid + 1, r, 2 * i + 2);
        segtree[i] = max(segtree[2 * i + 1], segtree[2 * i + 2]);
    }
}

int query(vector<int>& segtree, int l, int r, int tl, int tr, int i)
{
    if (l > tr || r < tl)
    {
        return -1;
    }
    else if (l >= tl && r <= tr)
    {
        return segtree[i];
    }
    else
    {
        int mid = (r - l) / 2 + l;
        return max(query(segtree, l, mid, tl, tr, 2 * i + 1), query(segtree, mid + 1, r, tl, tr, 2 * i + 2));
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            return 0;
        }

        vector<int> years(n);
        vector<int> rainfall(50000);
        vector<int> segtree(200000);
        for (int i = 0; i < n; i++)
        {
            int y;
            int r;
            cin >> y >> r;
            years[i] = y;
            rainfall[i] = r;
        }

        build(rainfall, segtree, 0, n - 1, 0);

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int x;
            int y;
            cin >> x >> y;

            int xi = lower_bound(years.begin(), years.end(), x) - years.begin();
            bool xb = xi < n && years[xi] == x;
            int yi = lower_bound(years.begin(), years.end(), y) - years.begin();
            bool yb = yi < n && years[yi] == y;

            if (!xb && !yb)
            {
                cout << "maybe" << endl;
            }
            else if (!xb)
            {
                if (query(segtree, 0, n - 1, xi, yi - 1, 0) >= rainfall[yi])
                {
                    cout << "false" << endl;
                }
                else
                {
                    cout << "maybe" << endl;
                }
            }
            else if (!yb)
            {
                if (query(segtree, 0, n - 1, xi + 1, yi - 1, 0) >= rainfall[xi])
                {
                    cout << "false" << endl;
                }
                else
                {
                    cout << "maybe" << endl;
                }
            }
            else
            {
                if (rainfall[xi] < rainfall[yi])
                {
                    cout << "false" << endl;
                }
                else if (query(segtree, 0, n - 1, xi + 1, yi - 1, 0) >= rainfall[yi])
                {
                    cout << "false" << endl;
                }
                else if (yi - xi + 1 == y - x + 1)
                {
                    cout << "true" << endl;
                }
                else
                {
                    cout << "maybe" << endl;
                }
            }
        }
        cout << endl;
    }

    return 0;
}