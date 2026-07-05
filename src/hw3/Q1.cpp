#include <iostream>
#include <vector>

using namespace std;

long long batmanacci(long long k, long long n, vector<long long>& fib)
{
    // base case:
    if (n == 2)
    {
        cout << "A" << endl;
        return 0;
    }
    else if (n == 1)
    {
        cout << "N" << endl;
        return 0;
    }

    if (k <= fib[n - 2]) // k is in left side of word (s_n-2)
    {
        return batmanacci(k, n - 2, fib);
    }
    else // k is in right side of word (s_n-1)
    {
        return batmanacci(k - fib[n - 2], n - 1, fib);
    }
}

int main()
{
    long long N, K;
    cin >> N >> K;

    // precompute string lengths
    vector<long long> fib(N + 1);
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < N + 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return batmanacci(K, N, fib);
}