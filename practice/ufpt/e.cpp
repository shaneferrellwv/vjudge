#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void minRoundSummands(int num)
{
    int numDigits = log10(num) + 1;
    int nonZeroDigits = 0;
    string numString = to_string(num);
    vector<string> summands;
    for (int i = 0; i < numDigits; i++)
    {
        if (numString[i] != '0')
        {
            nonZeroDigits++;

            string summand = "";
            summand += numString[i];
            int numZeros = numDigits - i - 1;
            for (int j = 0; j < numZeros; j++)
            {
                summand += '0';
            }
            summands.push_back(summand);
        }
    }

    // cout << num << ": " << numDigits << " " << nonZeroDigits << endl;
    cout << nonZeroDigits << endl;
    for (int i = 0; i < summands.size(); i++)
    {
        if (i != summands.size() - 1)
            cout << summands[i] << " ";
        else
            cout << summands[i] << endl;
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sums;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        sums.push_back(num);
    }

    for (int num : sums)
        minRoundSummands(num);
}