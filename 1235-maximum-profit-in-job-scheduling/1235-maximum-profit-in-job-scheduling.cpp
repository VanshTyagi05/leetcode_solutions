class Solution {
public:
    int N;
    int dp[50001];

    int helper(int idx, vector<vector<int>>& combined,
               vector<int>& startTimes) {
        if (idx >= N)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        // Case 1: Skip the current job
        int not_Take = helper(idx + 1, combined, startTimes);

        // Case 2: Take the current job
        // Use binary search to find the first job where combined[j][0] >=
        // combined[idx][1]
        int next_idx = lower_bound(startTimes.begin() + idx + 1,
                                   startTimes.end(), combined[idx][1]) -
                       startTimes.begin();

        int take = combined[idx][2] + helper(next_idx, combined, startTimes);

        return dp[idx] = max(take, not_Take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        N = startTime.size();
        memset(dp, -1, sizeof(dp));

        vector<vector<int>> combined;
        for (int i = 0; i < N; i++) {
            combined.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort by start time to use lower_bound effectively
        sort(combined.begin(), combined.end());

        // Create a separate vector of start times for the binary search tool
        vector<int> sortedStartTimes;
        for (auto& job : combined)
            sortedStartTimes.push_back(job[0]);

        return helper(0, combined, sortedStartTimes);
    }
};
