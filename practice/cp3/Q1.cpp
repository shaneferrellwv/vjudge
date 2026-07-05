#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct bottle {
    long long size, cost;
};

int main()
{
    int n;  // number of types of bottles
    long long L;  // liters of lemonade needed for party
    cin >> n >> L;

    vector<bottle> bottles(n); // list of size, price of each type of lemonade bottle available to purchase
    for (int i = 0; i < n; i++)
    {
        long long s;  // size of bottle i in liters
        s = pow(2, i);

        long long c;  // cost of bottle i in rubles
        cin >> c;

        bottles[i] = { s, c };
    }

    // adjust costs so that big bottles do not cost more than multiple smaller bottles
    for (int i = 1; i < n; i++)
    {
        bottles[i].cost = min(bottles[i].cost, 2 * bottles[i - 1].cost);
    }

    // greedy algorithm:
    // minimize unit cost (rubles/liter)
    long long lemonade = 0;
    long long total = 0;
    long long bestCost = numeric_limits<long long>::max();
    for (int i = n - 1; i >= 0; i--)
    {
        long long size = bottles[i].size;
        long long cost = bottles[i].cost;
        long long quantity = (L - lemonade) / size;

        lemonade += quantity * size;
        total += quantity * cost;
        bestCost = min(bestCost, total + (lemonade < L) * cost);
    }

    cout << bestCost << endl;

    return 0;
}