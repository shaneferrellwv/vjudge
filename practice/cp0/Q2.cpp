#include <iostream>

using namespace std;

int main()
{
    string input;
    cin >> input;

    int deletions = 0;
    for (int i = input.length() - 1; i >= 0; i--)
    {

        if (input[i] == '<')
        {
            input[i] = 'X';
            deletions++;
        }
        else if (deletions > 0)
        {
            input[i] = 'X';
            deletions--;
        }
    }

    for (char letter : input)
    {
        if (letter != 'X')
            cout << letter;
    }
}