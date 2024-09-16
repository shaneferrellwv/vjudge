#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

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
        if (instr == 'D')
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
    if (reverse)
    {
        std::reverse(list.begin(), list.end());
    }

    cout << "[";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.at(i);
        if (i < list.size() - 1)
        {
            cout << ",";
        }
        else
        {
            cout << "]" << endl;
        }
    }
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

        int index = 1;
        for (int j = 0; j < n; j++)
        {
            int element;
            int pos = listString.find(",");
            if (pos != string::npos)
            {
                element = stoi(listString.substr(index, pos));
                index = 0;
                listString = listString.substr(pos + 1, listString.length());
                list.push_back(element);
            }
            else
            {
                list.push_back(stoi(listString.substr(index, listString.find("]"))));
            }
        }

        bapc(p, list);
    }
}