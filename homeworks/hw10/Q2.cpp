class NumArray {
public:
    vector<int> v;
    vector<int> segtree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(n * 4, 0);
        v = nums;
        build(0, n - 1, 0);
    }
    
    void update(int index, int val) {
        update(0, n - 1, 0, index, val);
    }
    
    int sumRange(int left, int right) {
        return sum(left, right, 0, n - 1, 0);
    }

    void build(int l, int r, int i)
    {
        if (l == r)
        {
            segtree[i] = v[l];
            return;
        }
        else
        {
            int mid = (r - l) / 2 + l;
            build(l, mid, 2 * i + 1);
            build(mid + 1, r, 2 * i + 2);
            segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
        }
    }

    void update(int l, int r, int i, int ix, int x)
    {
        if (l > ix || ix > r)
        {
            return;
        }
        else if (l == r)
        {
            if (l == ix)
            {
                segtree[i] = x;
            }
            return;
        }
        else
        {
            int mid = (r - l) / 2 + l;
            update(l, mid, 2 * i + 1, ix, x);
            update(mid + 1, r, 2 * i + 2, ix, x);
            segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
        }
    }

    int sum (int l, int r, int tl, int tr, int i)
    {
        if (r < tl || l > tr)
        {
            return 0;
        }
        if (l <= tl && r >= tr)
        {
            return segtree[i];
        }
        else
        {
            int mid = (tr - tl) / 2 + tl;
            return sum(l, r, tl, mid, 2 * i + 1) + sum(l, r, mid + 1, tr, 2 * i + 2);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */