#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;  // number of types of bottles
    int L;  // liters of lemonade needed for party
    cin >> n >> L;

    vector<pair<int, int>> prices; // list of size, price of each type of lemonade bottle available to purchase
    for (int i = 1; i <= n; i++)
    {
        int s;  // size of bottle i in liters
        s = pow(2, i - 1);

        int c;  // cost of bottle i in rubles
        cin >> c;

        prices.push_back({ s, c });
    }

    long long biggestBottleSize = pow(2, n - 1);

    // greedy algorithm:
    // at each step, choose the bottle that satisfies:
    //      minimize unit cost (rubles/liter)
    long long total = 0;
    while (total < L)
    {
        int litersNeeded = L - total;
        int bestBottleIndex;
        int bestUnitPrice = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = prices[i];

            int quantityNeeded = litersNeeded / p.first;
            int unitPrice = quantityNeeded * p.second;
            if (unitPrice < bestUnitPrice)
            {
                bestUnitPrice = unitPrice;
                bestBottleIndex = i;
            }
        }
    }


    return 0;
}
