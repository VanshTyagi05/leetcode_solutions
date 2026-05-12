class Solution {
public:
    bool valid(int mid, vector<vector<int>>& tasks) {
        // now we have to verify that mid is sufficient to complete all task
        for (int i = 0; i < tasks.size(); i++) {
            if (mid >= tasks[i][1]) {
                mid -= tasks[i][0];
            } else {
                return false;
            }
        }

        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        // we have to sort the taska funciton in descending order of minimum
        // time
        sort(tasks.begin(), tasks.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return (a[1] - a[0]) > (b[1] - b[0]);
             });
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tasks[i][1];
        }
        int start = 1;
        int end = sum;
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (valid(mid, tasks)) {
                // aur chota answer dekho
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};