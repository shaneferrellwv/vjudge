#include <iostream>
#include <queue>

using namespace std;

struct price {
    int v;
    int d;
};

struct travel {
    int s;
    int t;
};

struct node {
    int min_cost;
    int max_cost;
    int max_profit;
};

void build(vector<int> &v, vector<node> &t, int i, int tl, int tr)
{
    if(tl == tr)
    {
        t[i] = {v[tl], v[tl], 0};
    }
    else
    {
        int tm = tl + (tr - tl) / 2;
        build(v, t, i * 2, tl, tm);
        build(v, t, i * 2 + 1, tm + 1, tr);

        node l = t[i * 2];
        node r = t[i * 2 + 1];

        int min_cost = min(l.min_cost, r.min_cost);
        int max_cost = max(l.max_cost, r.max_cost);
        int max_profit = max(r.max_cost - l.min_cost, max(l.max_profit, r.max_profit));
        t[i] = {min_cost, max_cost, max_profit};
    }
}

node query(vector<node> &t, int i, int tl, int tr, int l, int r)
{
    // invalid
    if(l > r)
    {
        return {0, 0, -1};
    }
    
    if(l == tl && r == tr)
    {
        return t[i];
    }
    
    int tm = tl + (tr - tl) / 2;

    node ql = query(t, i * 2, tl, tm, l, min(r, tm));
    node qr = query(t, i * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    
    if(ql.max_profit == -1)
    {
        return qr;
    }
    else if(qr.max_profit == -1)
    {
        return ql;
    }

    int min_cost = min(ql.min_cost, qr.min_cost);
    int max_cost = max(ql.max_cost, qr.max_cost);
    int max_profit = max(qr.max_cost - ql.min_cost, max(ql.max_profit, qr.max_profit));
    return {min_cost, max_cost, max_profit};
}

int main()
{
    int n;  // number of towns
    cin >> n;

    vector<price> prices(n);
    for (int i = 0; i < n; i++)
    {
        int v_i;    // base price
        int d_i;    // price fluctuaion
        cin >> v_i >> d_i;
        prices[i] = { v_i, d_i };
    }

    int q;  // number of travel plans
    cin >> q;

    vector<travel> trips(q);
    for (int i = 0; i < q; i++)
    {
        int s;  // starting town
        int t;  // ending town
        cin >> s >> t;
        trips[i] = {s - 1, t - 1};
    }

    vector<int> result(q);
    for(int i = 0; i < 7; i++)
    {
        vector<int> forward(n);
        vector<int> backward(n);
        for (int j = 0; j < n; j++)
        {
            forward[j] = prices[j].v;
            backward[n - j - 1] = prices[j].v;
        }

        const vector<int> sales = { 0, 1, 2, 3, 2, 1, 0 };
        for (int j = 0; j < n; j++)
        {
            int day = abs(j - i) % 7;
            forward[j] = forward[j] + prices[j].d * sales[day];
            backward[j] = backward[j] + prices[n - j - 1].d * sales[day];
        }

        // build forward segment tree
        vector<node> t(4 * n);
        build(forward, t, 1, 0, n - 1);
        for(int j = 0; j < trips.size(); j++)
        {
            if(trips[j].s % 7 == i && trips[j].s < trips[j].t)
            {
                node ans = query(t, 1, 0, n - 1, trips[j].s, trips[j].t);
                result[j] = ans.max_profit == -1 ? 0 : ans.max_profit;
            }
        }

        // build backward segment tree
        t = vector<node>(4 * n);
        build(backward, t, 1, 0, n - 1);
        for(int j = 0; j < trips.size(); j++)
        {
            int start = n - 1 - trips[j].s;
            int end = n - 1 - trips[j].t;
            if(start % 7 == i && start < end)
            {   
                node ans = query(t, 1, 0, n - 1, start, end);
                result[j] = ans.max_profit == -1 ? 0 : ans.max_profit;
            }
        }
    }

    for(int i = 0; i < q; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}