#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) 
{ 
    return a.second > b.second; 
} 

void maxReorderedSum(vector<int>& a, vector<pair<int, int>>& queries)
{
    map<int, int> m; // key: index, value: number of occurrences in queries
    for (pair<int, int> pair : queries)
    {
        for (int i = pair.first; i <= pair.second; i++)
        {
            m[i]++;
        }
    }

    // copy map to vector
    vector<pair< int, int>> A;
    for (auto& it : m)
    {
        A.push_back(it);
    }

    // sort vector by number of occurrences in queries
    sort(A.begin(), A.end(), cmp);

    // sort unordered vector
    sort(a.begin(), a.end());

    vector<int> reordered(a.size());

    int i = 0;
    while (!a.empty())
    {
        int value = a.back();
        a.pop_back();

        reordered[A[i].first - 1] = value;

        i++;
    }

    int sum = 0;
    for (pair<int, int> query : queries)
    {
        for (int i = query.first - 1; i < query.second; i++)
        {
            sum += reordered[i];
        }
    }

    cout << sum;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({ l, r });
    }

    maxReorderedSum(a, queries);
}