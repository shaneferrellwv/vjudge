#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool check(vector<int>& arr, int n, int k) 
{ 
    map<int, int> frequencies;
    for (int i = k; i < n; i++) 
    {
        frequencies[arr[i]]++; 
    }
    
    int duplicates = 0; 
    for (pair<int, int> element : frequencies) 
    {
        duplicates += element.second - 1; 
    }

    if (duplicates == 0) 
    {
        return true; 
    }
 
    for (int i = 1; i + k - 1 < n; i++)
    { 
        if (frequencies[arr[i + k - 1]] > 1) 
        {
            duplicates--; 
        }
 
        frequencies[arr[i + k - 1]]--; 
        frequencies[arr[i - 1]]++; 
 
        if (frequencies[arr[i - 1]] > 1) 
        {
            duplicates++; 
        }
 
        if (duplicates == 0) 
        {
            return true; 
        }
    } 
 
    return false; 
} 
 
int main() 
{ 
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int l = 0, r = n + 1; 
    int result = 0; 
    while (l < r)
    { 
        int mid = (l + r) / 2; 
        if (check(arr, n, mid))
        { 
            result = mid; 
            r = mid; 
        } 
        else
        {
            l = mid + 1; 
        }
    }

    cout << result << endl;
} 