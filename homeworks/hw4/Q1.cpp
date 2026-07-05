#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;

    deque<pair<int, int>> customers(N);
    for (int i = 0; i < N; i++)
    {
        int c, t;
        cin >> c >> t;

        customers[i] = { c, t };
    }
    
    sort(customers.begin(), customers.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first;
    });

    int total = 0;
    int spotsFilled = 0;
    vector<bool> spots(T, true);
    while (spotsFilled < T && !customers.empty())
    {
        pair<int, int> nextCustomer = customers.front();
        customers.pop_front();

        for (int time = nextCustomer.second; time >= 0; time--)
        {
            if (spots[time]) // if time slot open
            {
                spots[time] = false;
                spotsFilled++;
                total += nextCustomer.first;
                break;
            }
        }
    }

    cout << total << endl;
}