#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

struct sprinkler {
    double left, right;

    sprinkler(int position, int radius, int width)
    {
        // d = sqrt(r^2 - 1/4 * w^2)
        double d = sqrt((radius * radius) - (0.25 * (width * width)));
        left = position - d;
        right = position + d;
    }
};

int main()
{
    int n; // number of sprinklers
    int l; // length of grass strip
    int w; // width of grass strip

    while (cin >> n >> l >> w)
    {
        vector<sprinkler> sprinklers;
        for (int i = 0; i < n; i++)
        {
            int x; // position of sprinkler
            int r; // radius
            cin >> x >> r;

            // don't even consider sprinklers who can't spray the entire width of the grass strip
            if (r > 0.5 * w)
            {
                sprinklers.push_back(sprinkler(x, r, w));
            }
        }

        // sort sprinklers by leftmost spray width
        sort(sprinklers.begin(), sprinklers.end(), [](const sprinkler& a, const sprinkler& b){return a.left < b.left;});

        // greedy algorithm to choose the best sprinkler at each step which:
        //      satisfies the condition:
        //          left range of sprinkler begins in portion of grass watered so far
        //      maximizes the condition:
        //          right range of sprinkler
        double covered = 0;
        int total = 0;
        bool possible = true;
        while (covered < l)
        {
            // find the sprinkler that sprays the beginning portion of unwatered grass
            double farthestRange = covered;
            for (sprinkler s : sprinklers)
            {
                // if sprinkler starts in the portion that is already watered
                // AND sprays farther than any other sprinkler seen so far
                if (s.left <= covered && s.right > farthestRange)
                {
                    farthestRange = s.right;
                }
            }

            // if the best sprinkler does not water any additional grass
            if (farthestRange <= covered)
            {
                // then we cannot choose another sprinkler to water the next unwatered section of grass
                total = -1;
                break;
            }

            // update portion of grass that is watered and number of sprinklers needed
            covered = farthestRange;
            total++;
        }

        cout << total << endl;
    }
    return 0;
}