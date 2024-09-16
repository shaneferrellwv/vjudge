#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, int, int> countBreeds(int a, int b, string breeds[])
{
    int holsteins = 0, guernseys = 0, jerseys = 0;
    for (int i = a - 1; i < b; i++)
    {
        if (breeds[i] == "1")
        {
            holsteins++;
        }
        else if (breeds[i] == "2")
        {
            guernseys++;
        }
        else if (breeds[i] == "3")
        {
            jerseys++;
        }
    }
    return{ holsteins, guernseys, jerseys };
}

int main()
{
    ifstream input("bcount.in");
    ofstream output("bcount.out");
    string N, Q;
    getline(input, N, ' ');
    getline(input, Q);
    string breeds[stoi(N)];
    for (int i = 0; i < stoi(N); i++)
    {   
        string breed;
        getline(input, breed);
        breeds[i] = breed;
    }

    vector<tuple<int, int, int>> results;
    for (int i = 0; i < stoi(Q); i++)
    {
        string a, b;
        getline(input, a, ' ');
        getline(input, b);

        results.push_back(countBreeds(stoi(a), stoi(b), breeds));
    }

    for (int i = 0; i < stoi(Q); i++)
    {
        output << get<0>(results[i]) << " " << get<1>(results[i]) << " " << get<2>(results[i]) << endl;
    }
}
