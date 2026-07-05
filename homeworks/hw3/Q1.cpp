#include <iostream>
#include <vector>

using namespace std;

string batmanacci(long long n, long long k, vector<long long>& lengths)
{
    // base cases
    if (n == 1)
    {
        return "N";
    }
    else if (n == 2)
    {
        return "A";
    }
    else
    {
        if (k <= lengths[n - 2]) // if k is in the s_n-2 part of s_n
        {
            return batmanacci(n - 2, k, lengths);
        }
        else // if k is in the s_n-1 part of s_n
        {
            return batmanacci(n - 1, k - lengths[n - 2], lengths);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<long long> lengths(n + 1);

    lengths[1] = 1;
    lengths[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        lengths[i] = lengths[i - 2] + lengths[i - 1];
        
        if (lengths[i] > 1000000000000000000)
        {
            lengths[i] = 1000000000000000001;
        }
    }

    cout << batmanacci(n, k, lengths) << endl;
}