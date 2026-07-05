#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void suspicion(vector<pair<int, string>>& tasks)
{
    for (pair<int, string> task : tasks)
    {
        int i = 0;
        int length = task.first;
        string polycarp = task.second;
        unordered_set<char> seen;

        while (i < length)
        {
            if (i == length - 1)
            {
                if (!seen.count(polycarp[i]))
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                    break;
            }

            if (polycarp[i] == polycarp[i + 1])
            {
                i++;
            }
            else if (polycarp[i] != polycarp[i + 1])
            {
                if (seen.count(polycarp[i + 1]))
                {
                    cout << "NO" << endl;
                    break;
                }
                else
                {
                    seen.emplace(polycarp[i]);
                    i++;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    vector<pair<int, string>> tasks; // days (length of string), string

    for (int i = 0; i < t; i++)
    {
        int days;
        string polycarp;

        cin >> days >> polycarp;
        tasks.push_back({days, polycarp});
    }

    suspicion(tasks);
}
