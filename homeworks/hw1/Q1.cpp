#include <iostream>
#include <vector>

using namespace std;

void divideIt(int q, vector<long long>& queries)
{
    for (long long query : queries)
    {
        int ops = 0;
        while (query != 1)
        {
            if (query % 5 == 0)
            {
                ops += 3;
                query /= 5;
            }
            else if (query % 3 == 0)
            {
                ops += 2;
                query /= 3;
            }
            else if (query % 2 == 0)
            {
                ops += 1;
                query /= 2;
            }
            else
            {
                ops = -1;
                break;
            }
        }
        cout << ops << endl;
    }
}

int main()
{
    int q;
    cin >> q;

    vector<long long> queries;

    for (int i = 0; i < q; i++)
    {
        long long query;
        cin >> query;
        queries.push_back(query);
    }

    divideIt(q, queries);
}
