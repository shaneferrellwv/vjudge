#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solve(vector<int>& gift, int start, int end, int depth)
{
    // base cases:
    if (start == -1 || end == -1 || start > end)
    {
        return vector<int>();
    }
    if (start == end)
    {
        return vector<int>(1, depth);
    }

    // find max element
    int maxIndex = start;
    for (int i = start + 1; i <= end; i++)
    {
        if (gift[i] > gift[maxIndex])
        {
            maxIndex = i;
        }
    }

    vector<int> left = solve(gift, start, maxIndex - 1, depth + 1);
    vector<int> right = solve(gift, maxIndex + 1, end, depth + 1);
    left.push_back(depth);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    int G; // number of gifts
    cin >> G;

    for (int i = 0; i < G; i++)
    {
        int N;
        cin >> N;   

        vector<int> gift(N);
        for (int j = 0; j < N; j++)
        {
            cin >> gift[j];
        }

        vector<int> result = solve(gift, 0, N - 1, 0);
        for (int j = 0; j < N; j++)
        {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
