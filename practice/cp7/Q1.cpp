#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int h;
    string path;
    cin >> h;
    cin.ignore();
    getline(cin, path);

    int root = pow(2, h + 1) - 1;
    int node = 1;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == 'L')
        {
            node = 2 * node;
        }
        else if (path[i] == 'R')
        {
            node = 2 * node + 1;
        }
        h++;
    }

    cout << root - node + 1 << endl;

    return 0;
}