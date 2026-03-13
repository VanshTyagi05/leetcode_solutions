class Solution {
public:
    int N;
    int dp[50001];

    int helper(int idx, vector<vector<int>>& combined) {
        if (idx >= N) {
            return 0;
        }
        if (dp[idx] != -1)
            return dp[idx];

        // 1. Choice: Not Take
        int not_Take = helper(idx + 1, combined);

        // 2. Choice: Take
        // Binary Search to find the first job whose startTime >= current job's
        // endTime
        int next_idx = N;
        int low = idx + 1;
        int high = N - 1;
        int target = combined[idx][1]; // current job's end time

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (combined[mid][0] >= target) {
                next_idx = mid;
                high = mid - 1; // Look for an even earlier job that still fits
            } else {
                low = mid + 1;
            }
        }

        int take = combined[idx][2] + helper(next_idx, combined);

        return dp[idx] = max(take, not_Take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        N = n;
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> combined;
        for (int i = 0; i < n; i++) {
            combined.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Must sort by startTime for binary search to work
        sort(combined.begin(), combined.end());

        return helper(0, combined);
    }
};
