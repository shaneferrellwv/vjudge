#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        // determine position of each number in permutation
        vector<long long> v(n + 1);
        vector<long long> position(n + 1);
        for (long long i = 1; i <= n; i++)
        {
            cin >> v[i];
            position[v[i]] = i;
        }

        long long result = 0;
        // count number of elements out of order
        for (long long i = 2; i <= n; i++)
        {
            if (position[i] < position[i - 1])
            {
                result++;
            }
        }

        cout << result << endl;
    }
}
