class Solution {
public:
    int t[1001];
    int n;
    int recur(int idx, vector<int>& arr, int& d) {
        if (t[idx] != -1)
            return t[idx];
        int result = 1;
        // ek bar left chle jao
        for (int j = idx - 1; j >= max(0, idx - d); j--) {
            if (arr[j] >= arr[idx])
                break;
            result = max(result, 1 + recur(j, arr, d));
        }

        // ek bar right chle jao
        for (int j = idx + 1; j <= min(n - 1, idx + d); j++) {
            if (arr[j] >= arr[idx])
                break;
            result = max(result, 1 + recur(j, arr, d));
        }

        return t[idx] = result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        int result = 1;
        for (int i = 0; i < n; i++) {
            result = max(result, recur(i, arr, d));
        }

        return result;
    }
};