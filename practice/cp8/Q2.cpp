#include <iostream>
#include <vector>

using namespace std;

void flip(vector<int>& tree, int n, int i)
{
    tree[n + i] = !tree[n + i];
    for (int j = (n + i) / 2; j > 0; j /= 2)
    {
        tree[j] = tree[2 * j] + tree[2 * j + 1];
    }
}

int count(vector<int>& tree, int n, int l, int r)
{
    int count = 0;
    l += n;
    r += n;
    while (l <= r)
    {
        if (l % 2 == 1)
        {
            count += tree[l];
            l++;
        }
        if (r % 2 == 0)
        {
            count += tree[r];
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> tree(2 * n, 0);
    for (int j = 0; j < k; j++)
    {
        char op;
        cin >> op;

        if (op == 'F')
        {
            int i;
            cin >> i;
            flip(tree, n, i);
        }
        else if (op == 'C')
        {
            int l, r;
            cin >> l >> r;
            cout << count(tree, n, l, r) << endl;
        }
        
    }

    return 0;
}