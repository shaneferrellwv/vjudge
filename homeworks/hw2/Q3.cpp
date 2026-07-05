#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> stack;
    bool playerOneTurn = true;
    for (char c : s)
    {
        if (!stack.empty() && stack.top() == c)
        {
            stack.pop();
            playerOneTurn = !playerOneTurn;
        }
        else
        {
            stack.push(c);
        }
    }

    if (playerOneTurn)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}