#include <iostream>
#include <vector>

using namespace std;

void update(vector<long long>& tree, int i, int x)
{
    i++;
    while (i <= tree.size())
    {
        tree[i] += x;
        i += i & -i;
    }
}

long long query(vector<long long>& tree, int i)
{
    if (i == 0)
    {
        return 0;
    }
    else
    {
        long long sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= i & -i;
        }
        return sum;
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, & q);

    vector<long long> tree(5000001, 0);
    for (int j = 0; j < q; j++)
    {
        char op;
        scanf(" %c", &op);

        if (op == '+')
        {
            int i, x;
            scanf("%d %d", &i, &x);
            update(tree, i, x);
        }
        else if (op == '?')
        {
            int i;
            scanf("%d", &i);

            long long x = query(tree, i);
            printf("%lld\n", x);
        }
    }

    return 0;
}