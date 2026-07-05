#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxWealthyPeople()
{
    long long n, wealthLevel;
    cin >> n >> wealthLevel;

    vector<long long> savings;
    long long total = 0;
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        savings.push_back(a);
        total += a;
    }

    if (total / n < wealthLevel)
    {
        sort(savings.begin(), savings.end());

        long long remainingPeople = n;
        for (long long i = 0; i < n; i++)
        {
            total -= savings[i];
            remainingPeople--;
            if (remainingPeople == 0)
            {
                cout << remainingPeople << endl;
                return 0;
            }
            else if (total / remainingPeople >= wealthLevel)
            {
                cout << remainingPeople << endl;
                return 0;
            }
        }
    }
    else // edge case: everyone could already be wealthy
    {
        cout << n << endl;
        return 0;
    }
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        findMaxWealthyPeople();
    }

    return 0;
}