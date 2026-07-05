class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        vector<int> temp(n + m); 
        vector<pair<int, int>> v(n);
        unordered_map<int, int> hash; 
        
        for(int i = 0; i < n; i++)
        {
            temp[i] = nums2[i];
            v[i] = {nums1[i], nums2[i]};
        }
        
        for(int i = 0; i < m; i++)
        {
            temp[n + i] = queries[i][1];
        }

        sort(temp.begin(), temp.end()); 
        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            else
            {
                return a.first > b.first;
            }
        }); 
        
        int updated = 0; 
        for(int i = 0; i < n + m; i++)
        {
            if (hash.find(temp[i]) != hash.end())
            {
                continue; 
            }
            hash[temp[i]] = updated++; 
        }
        
        n = updated + 1;
        vector<int> segtree(4 * n + 1, -1);
        for(int i = 0; i < m; i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0])
            {
                return a[1] > b[1];
            }
            else
            {
                return a[0] > b[0];
            }
        });
        
        vector<int> result(m);
        int j = 0; 
        for (int i = 0; i < m; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int idx = queries[i][2];
            while (j < nums1.size() and v[j].first >= x)
            {
                int X = v[j].first;
                int Y = v[j].second; 
                int val = X + Y; 
                int index = hash[Y]; 
                update(0, n - 1, 0, index, val, segtree); 
                j++; 
            }
            
            int maxi = query(0, n - 1, 0, hash[y], n, segtree);
            result[idx] = maxi; 
        }
    
        return result;
    }
        
    void update(int l, int r, int i, int idx, int x, vector<int>& segtree)
    {
        if(l == r)
        {
            segtree[i] = max(x, segtree[i]);
            return; 
        }
        
        int mid = (l + r) / 2; 
        if (idx <= mid)
        {
            update(l, mid, 2 * i + 1, idx, x, segtree);
        }
        else {
            update(mid + 1, r, 2 * i + 2, idx, x, segtree);
        }
        
        segtree[i] = max(segtree[2 * i + 1], segtree[2 * i + 2]);
    }
    
    int query(int tl, int tr, int i, int l, int r, vector<int>& segtree)
    {
        if (tl > r or tr < l)
        {
            return INT_MIN;
        }
        if (tl >= l and tr <= r)
        {
            return segtree[i];
        }
        else
        {
            int mid = (tl + tr) / 2;
            int left = query(tl, mid, 2 * i + 1, l, r, segtree);
            int right = query(mid + 1, tr, 2 * i + 2, l, r, segtree);
            return max(left, right); 
        }
    }
};