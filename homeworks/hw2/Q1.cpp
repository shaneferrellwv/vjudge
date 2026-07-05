#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int h, c;
    cin >> h >> c;

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> minHeap;
    for (long long i = 0; i < c; i++)
    {
        long long a, d;
        cin >> a >> d;
        minHeap.push({ a + d, d });
    }

    for (long long i = 0; i < h; i++)
    {
        pair<long long, long long> annoyedCoworker = { minHeap.top().first + minHeap.top().second, minHeap.top().second };
        minHeap.pop();
        minHeap.push(annoyedCoworker);
    }

    long long maxAnnoyance = -1;
    while (!minHeap.empty())
    {
        long long annoyance = minHeap.top().first - minHeap.top().second;
        minHeap.pop();
        maxAnnoyance = max(maxAnnoyance, annoyance);
    }

    cout << maxAnnoyance << endl;
}