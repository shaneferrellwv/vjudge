#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;

    vector<int> listeners;
    for (int i = 0; i < N; i++)
    {
        int commercialBreak;
        cin >> commercialBreak;
        listeners.push_back(commercialBreak);
    }

    int localMax = 0, globalMax = 0;
    for (int i = 0; i < N; i++)
    {
        int profit = listeners[i] - P;
        localMax = max(profit, localMax + profit);
        globalMax = max(localMax, globalMax);
    }
    cout << globalMax;
}