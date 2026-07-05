class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefixSum(nums.size() + 1);
        for (int i = 1; i < nums.size() + 1; i++)
        {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }

        set<long long> sortedSums = { 0 };
        for (int i = 0; i < prefixSum.size(); i++)
        {
            long long sum = prefixSum[i];
            sortedSums.insert(sum);
            sortedSums.insert(sum - lower);
            sortedSums.insert(sum - upper);
        }
        
        unordered_map<long long, int> compressed;
        int index = 0;
        for (long long num : sortedSums) 
        {
            compressed[num] = index++;
        }
        
        int n = sortedSums.size();
        vector<int> segtree(4 * n, 0);
        
        int count = 0;
        for (int i = 0; i < prefixSum.size(); i++)
        {
            long long sum = prefixSum[i];
            int l = compressed[sum - upper];
            int r = compressed[sum - lower];
            count += query(segtree, 0, n - 1, l, r, 1);
            update(segtree, 0, n - 1, compressed[sum], 1);
        }
        
        return count;
    }
    
    void update(vector<int>& segtree, int l, int r, int x, int i)
    {
        if (l == r)
        {
            segtree[i]++;
        }
        else
        {
            int mid = (r - l) / 2 + l;
            if (x <= mid)
            {
                update(segtree, l, mid, x, 2 * i);
            }
            else
            {
                update(segtree, mid + 1, r, x, 2 * i + 1);
            }
            segtree[i] = segtree[2 * i] + segtree[2 * i + 1];
        }
    }
    
    int query(vector<int>& segtree, int l, int r, int tl, int tr, int i)
    {
        if (tl > r || tr < l) 
        {
            return 0;
        }
        if (tl <= l && tr >= r)
        {
            return segtree[i];
        }
        int mid = l + (r - l) / 2;
        return query(segtree, l, mid, tl, tr, 2 * i) + query(segtree, mid + 1, r, tl, tr, 2 * i + 1);
    }
};