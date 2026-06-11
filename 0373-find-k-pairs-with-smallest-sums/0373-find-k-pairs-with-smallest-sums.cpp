class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vector<vector<int>> ans;
        set<pair<int, int>> visited;

        visited.insert({0, 0}); // Good practice to insert the initial state

        while (k-- > 0 && !pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int idx1 = it.second.first;
            int idx2 = it.second.second;
            ans.push_back({nums1[idx1], nums2[idx2]});

            // FIX 1: Check bounds BEFORE calculating and pushing total1
            if (idx2 + 1 < n2 && !visited.contains({idx1, idx2 + 1})) {
                int total1 = nums1[idx1] + nums2[idx2 + 1];
                pq.push({total1, {idx1, idx2 + 1}});
                visited.insert({idx1, idx2 + 1});
            }

            // FIX 2: Check bounds BEFORE calculating and pushing total2
            if (idx1 + 1 < n1 && !visited.contains({idx1 + 1, idx2})) {
                int total2 = nums1[idx1 + 1] + nums2[idx2];
                pq.push({total2, {idx1 + 1, idx2}});
                visited.insert({idx1 + 1, idx2});
            }
        }
        return ans;
    }
};
