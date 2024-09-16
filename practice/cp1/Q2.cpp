#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> scores;
    for (int i = -10; i <= 10; i++)
    {
        scores[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;

        scores[t]++;
    }

    int couples = 0;
    for (int i = -10; i < 0; i++)
    {
        couples += scores[i] * scores[-i];
    }
    couples += scores[0] * (scores[0] - 1) / 2;

    cout << couples << endl;
}