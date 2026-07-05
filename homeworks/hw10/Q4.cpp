class Solution {
public:
    vector<int> segtree;

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0])
            {
                return a[0] < b[0];
            }
            else
            {
                return a[1] > b[1];
            }
        });

        segtree.clear();
        segtree.resize(4 * n);
        build(0, n - 1, 1);

        vector<vector<int>> result(people.size(), vector<int>());
        for(int i = 0; i < people.size(); i++)
        {
            int j = query(0, n - 1, people[i][1] + 1, 1);
            result[j] = people[i];
            update(0, n - 1, j, 1);
        }
        return result;
    }

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            segtree[i] = 1; 
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * i);
        build(mid + 1, r, 2 * i + 1);
        segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
    }

    int query(int l, int r, int ix, int i)
    {
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) / 2;
        int left = segtree[2 * i];
        int right = segtree[2 * i + 1];
        if (ix > left)
        {
            return query(mid + 1, r, ix - left, 2 * i + 1);
        }
        else
        {
            return query(l, mid, ix, 2 * i);
        }
    }

    void update(int l, int r, int idx, int i)
    {
        if(l == r)
        {
            segtree[i] = 0; 
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(l, mid, idx, 2 * i);
        }
        else
        {
            update(mid + 1, r, idx, 2  * i + 1);
        }
        segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
    }
};