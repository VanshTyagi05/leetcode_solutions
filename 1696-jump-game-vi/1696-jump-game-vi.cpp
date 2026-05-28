class Solution {
public:
    int n;
    int t[100001];
    priority_queue<pair<int, int>> pq;
    int recur(int i, vector<int>& nums, int k) {
        if (i == n - 1)
            return nums[n - 1];
        if (t[i] != -1)
            return t[i];

        while (!pq.empty() && pq.top().second > i + k) {
            pq.pop();
        }
        int max_possible_subsequent = pq.top().first;

        // 3. Save the result in our memo table
        t[i] = nums[i] + max_possible_subsequent;

        // 4. Push the newly computed result and its index into the heap
        pq.push({t[i], i});

        return t[i];
    }
    int maxResult(vector<int>& nums, int k) {
        n = nums.size();
        if(n==1)return nums[0];
        memset(t, -1, sizeof(t));
        // Base case initialization for the heap
        pq.push({nums[n - 1], n - 1});

        // We must process from right to left (backwards) to build the heap
        // dependencies
        for (int i = n - 2; i >= 0; i--) {
            recur(i, nums, k);
        }

        return t[0];
    }
};