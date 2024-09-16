#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> names; // key: name, value: number of users with that name

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        if (names.find(name) == names.end())
        {
            names[name] = 0;
            cout << "OK" << endl;
        }
        else
        {
            names[name]++;
            cout << name << names[name] << endl;
        }
    }
    return 0;
}