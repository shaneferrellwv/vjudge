#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;  // number of people in queue
    cin >> n;

    vector<int> queue(n);
    for (int i = 0; i < n; i++)
    {
        int t; // time before person i is disappointed
        cin >> t;

        queue[i] = t;
    }

    sort(queue.begin(), queue.end());

    long long total = 0;
    long long notDisappointedCount = 0;
    for (int i = 0; i < n; i++)
    {
        // if time passed is not enough time for person to be disappointed
        if (total <= queue[i])
        {
            // person can stay in line at their spot and will get served
            total += queue[i];
            notDisappointedCount++;
        }
        else
        {
            // person gets sent to back of line and will not get served before being disappointed
        }
    }

    cout << notDisappointedCount << endl;

    return 0;
}