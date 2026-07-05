#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> laptops;
    for (int i = 0; i < n; i++)
    {
        int price, quality;
        cin >> price >> quality;

        laptops.push_back({ price, quality });
    }
    
    sort(laptops.begin(), laptops.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.first > b.first;
    });

    pair<int, int> worstLaptop = laptops[0];
    for (pair<int, int>& laptop : laptops)
    {
        if (laptop.first < worstLaptop.first && laptop.second > worstLaptop.second)
        {
            cout << "Happy Alex" << endl;
            return 0;
        }
        else if (laptop.second < worstLaptop.second)
        {
            worstLaptop = laptop;
        }
    }

    cout << "Poor Alex" << endl;
}