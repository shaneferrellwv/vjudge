#include <iostream>
#include <vector>

using namespace std;

struct op
{
    int l, r, d;

    op() {}

    op(int l, int r, int d)
    {
        this->l = l;
        this->r = r;
        this->d = d;
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<op> ops(m + 1);
    for (int i = 0; i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        ops[i] = op(l, r, d);
    }

    vector<long long> op_count(m + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        op_count[x]++;
        if (y + 1 <= m)
        {
            op_count[y + 1]--;
        }
    }

    for (int i = 1; i <= m; i++) 
    {
        op_count[i] += op_count[i - 1];
    }

    vector<long long> diff(n + 2, 0);
    for (int i = 0; i < m; i++)
    {
        op o = ops[i];
        diff[o.l] += o.d * op_count[i + 1];
        if (o.r + 1 <= n)
        {
            diff[o.r + 1] -= o.d * op_count[i + 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        a[i] += diff[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
