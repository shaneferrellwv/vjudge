#include <iostream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

void bapc(string p, deque<int>& list)
{
    bool reverse = false;
    for (int i = 0; i < p.length(); i++)
    {
        char instr = p.at(i);
        if (instr == 'R')
        {
            reverse = !reverse;
        }
        else if (instr == 'D')
        {
            if (list.size() == 0)
            {
                cout << "error" << endl;
                return;
            }

            if (reverse)
            {
                list.pop_back();
            }
            else
            {
                list.pop_front();
            }
        }
    }

    // print solution
    cout << "[";
    if (reverse)
    {
        for (int i = list.size() - 1; i >= 0; i--)
        {
            cout << list.at(i);
            if (i > 0)
            {
                cout << ",";
            }
        }
    }
    else
    {
        for (int i = 0; i < list.size(); i++)
        {
            cout << list.at(i);
            if (i < list.size() - 1)
            {
                cout << ",";
            }
        }
    }
    cout << "]" << endl;
}

int main()
{
    int N; // number of test cases
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string p; // BAPC program instructions
        int n; // number of elements in integer list
        string listString; // unparsed integer list
        deque<int> list; // integer list

        cin >> p >> n >> listString;

        listString = listString.substr(1, listString.length() - 2);

        stringstream ss(listString);
        string temp;
        while (getline(ss, temp, ','))
        {
            if (!temp.empty())
            {
                list.push_back(stoi(temp));
            }
        }

        bapc(p, list);
    }
}