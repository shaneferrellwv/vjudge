#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct outpost
{
    int x, y;

    outpost(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

double calculateDistance(outpost* a, outpost* b)
{
    return sqrt(((a->x - b->x) * (a->x - b->x)) + ((a->y - b->y) * (a->y - b->y)));
}

struct edge
{
    int u, v;
    double w;

    edge(int u, int v, double w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int find(int u, vector<int>& parent)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u], parent);
    }

    return parent[u];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank)
{
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int main()
{
    int N; // number of test cases
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int S;  // number of satellite channels
        int P;  // number of radio outposts
        cin >> S >> P;

        vector<outpost> radios;
        for (int j = 0; j < P; j++)
        {
            int x, y;
            cin >> x >> y;
            radios.push_back(outpost(x, y));
        }

        // use Kruskal's algorithm to create an MST
        // create an edge between all radio outposts
        vector<edge> edgeList;
        for (int u = 0; u < P; u++)
        {
            for (int v = u + 1; v < P; v++)
            {
                outpost* a = &radios[u];
                outpost* b = &radios[v];
                edgeList.push_back(edge(u, v, calculateDistance(a, b)));
            }
        }

        // sort edges by distance
        sort(edgeList.begin(), edgeList.end(), [](const edge& a, const edge& b){return a.w < b.w;});

        // begin kruskal's
        vector<int> parent(P);
        vector<int> rank(P, 0);
        for (int u = 0; u < P; u++)
        {
            parent[u] = u;
        }

        // construct min spanning tree
        vector<edge> mst;
        for (edge e : edgeList)
        {
            if (find(e.u, parent) != find(e.v, parent))
            {
                unionSets(e.u, e.v, parent, rank);
                mst.push_back(e);
            }

            // satellite communication can cover the last S edges
            if (mst.size() == P - S)
            {
                break;
            }
        }

        if (mst.size() == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << fixed << setprecision(2) << mst.back().w << endl;
        }
    }

    return 0;
}