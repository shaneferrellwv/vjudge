#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct lesson {
    int start, end, index;
};

int main()
{
    int n;
    cin >> n;

    vector<lesson> lessons;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;

        lesson l;
        l.start = start;
        l.end = end;
        l.index = i + 1;

        lessons.push_back(l);
    }
    
    vector<int> cancellations;
    vector<int> overlaps(n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (lessons[j].start < lessons[i].end && lessons[i].start < lessons[j].end)
            {
                overlaps[i]++;
                overlaps[j]++;
                total++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (overlaps[i] == total)
        {
            cancellations.push_back(i);
        }
    }

    cout << cancellations.size() << endl;
    for (int i : cancellations)
    {
        cout << i + 1 << " ";
    }

    return 0;
}