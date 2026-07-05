#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int a_i;
        cin >> a_i;
        a[i] = a_i;
    }

    vector<int> a_max(n);
    a_max[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        a_max[i] = max(a_max[i - 1], a[i]);
    }

    vector<int> a_min(n);
    a_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        a_min[i] = min(a_min[i + 1], a[i]);
    }

    int pivots = 0;
    for (int i = 0; i < n; i++)
    {
        if (a_max[i] == a[i] && a_min[i] == a[i])
        {
            pivots++;
        }
    }

    cout << pivots << endl;

    return 0;
}