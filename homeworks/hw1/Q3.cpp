#include <iostream>
#include <string>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
            return 0;

        int miles = 0, time = 0;
        for (int i = 0; i < n; i++)
        {
            int mph, hours;
            cin >> mph >> hours;

            int elapsed = hours - time;
            miles += mph * elapsed;
            time += elapsed;
        }

        cout << miles << " miles" << endl;
    }
}