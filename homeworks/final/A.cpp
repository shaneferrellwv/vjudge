vector<vector<int>> buildSparseTable(vector<int>& arr) {
    int n = arr.size();
    int maxLog = log2(n) + 1;
    vector<vector<int>> sparse(n, vector<int>(maxLog));

    for (int i = 0; i < n; i++) {
        sparse[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    return sparse;
}

int rangeMinQuery(vector<vector<int>>& sparse, int l, int r) {
    int j = log2(r - l + 1);
    return min(sparse[l][j], sparse[r - (1 << j) + 1][j]);
}