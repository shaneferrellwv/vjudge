#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
    string n;
    getline(cin, n);

    unordered_set<string> keywords;
    for (int i = 0; i < stoi(n); i++)
    {
        string k;
        getline(cin, k);

        string keyword;
        for (char c : k)
        {
            if (c == '-')
                c = ' ';
            keyword += tolower(c);
        }
        keywords.emplace(keyword);
    }

    cout << keywords.size() << endl;
}