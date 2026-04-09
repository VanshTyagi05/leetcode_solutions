class Solution {
public:
    void buildSegTree(int i, int l, int r,
                      vector<int>& segtree, // ✅ pass by reference
                      vector<int>& arr) {
        if (l == r) {
            segtree[i] = l;
            return; // ✅ missing return added
        }
        int mid = l + (r - l) / 2;
        buildSegTree(2 * i + 1, l, mid, segtree, arr);
        buildSegTree(2 * i + 2, mid + 1, r, segtree, arr);
        int left = segtree[2 * i + 1];
        int right = segtree[2 * i + 2];
        if (arr[left] >= arr[right]) {
            segtree[i] = left;
        } else {
            segtree[i] = right;
        }
    }

    int RMIQ(int start, int end, int i, int l, int r, vector<int>& segtree,
             vector<int>& arr) {
        if (end < l || start > r) {
            return -1;
        }
        if (l >= start && r <= end) {
            return segtree[i];
        }
        int mid = l + (r - l) / 2;
        int leftmaxIdx = RMIQ(start, end, 2 * i + 1, l, mid, segtree, arr);
        int rightmaxIdx = RMIQ(start, end, 2 * i + 2, mid + 1, r, segtree, arr);
        if (leftmaxIdx == -1)
            return rightmaxIdx;
        if (rightmaxIdx == -1)
            return leftmaxIdx;
        return (arr[leftmaxIdx] >= arr[rightmaxIdx]) ? leftmaxIdx : rightmaxIdx;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> segtree(4 * n);
        buildSegTree(0, 0, n - 1, segtree, heights);
        vector<int> ans;

        for (int i = 0; i < (int)queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            int maxIdx = max(a, b);
            int minIdx = min(a, b);

            if (maxIdx == minIdx ||
                heights[maxIdx] > heights[minIdx]) { // ✅ was >=, should be >
                ans.push_back(maxIdx);
                continue; // ✅ was missing — skips binary search for this query
            }

            // ✅ Binary search for leftmost index > maxIdx where height is
            // sufficient
            int l = maxIdx + 1;
            int r = n - 1;
            int result_idx = -1; // ✅ use -1 as sentinel instead of INT_MAX
            int threshold = max(heights[minIdx], heights[maxIdx]);

            while (l <= r) {
                int mid = l + (r - l) / 2;
                // ✅ Query [l, mid] to check if a valid index exists in left
                // half
                int idx = RMIQ(l, mid, 0, 0, n - 1, segtree, heights);

                if (idx != -1 && heights[idx] > threshold) {
                    result_idx = idx; // ✅ candidate found, try to go left
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(result_idx);
        }
        return ans;
    }
};