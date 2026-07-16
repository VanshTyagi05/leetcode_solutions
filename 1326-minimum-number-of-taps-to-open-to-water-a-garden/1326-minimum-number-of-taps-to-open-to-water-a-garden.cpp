class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> v;
        for (int i = 0; i < ranges.size(); i++) {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            v.push_back({left, right});
        }

        sort(v.begin(), v.end());
        int currend = 0;
        int ans = 0;
        int i = 0;
        int m = v.size();
        while (currend < n) {
            int farthest = currend;
            while (i < m && v[i].first <= currend) {
                farthest = max(farthest, v[i].second);
                i++;
            }
            if (farthest == currend) {
                // koi chnge nhi aya mtlb gap h
                return -1;
            }

            ans++;
            currend = farthest;
        }
        return ans;
    }
};