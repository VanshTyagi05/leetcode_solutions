class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        // plan A going for landslide and then water slide
        for (int i = 0; i < n; i++) {
            // atrting at ith land slide
            int l_strt = landStartTime[i];
            int l_time = landDuration[i];
            for (int j = 0; j < m; j++) {
                int w_strt = waterStartTime[j];
                int w_time = waterDuration[j];
                if (l_strt + l_time >= w_strt) {
                    // posible case
                    ans = min(ans, w_time + l_time + l_strt);
                } else {
                    ans = min(ans, w_strt + w_time);
                }
                // then going at jth water slide
            }
        }

        // plan B going for water slide first and then going for land slide
        for (int j = 0; j < m; j++) {
            int w_strt = waterStartTime[j];
            int w_time = waterDuration[j];
            for (int i = 0; i < n; i++) {

                int l_strt = landStartTime[i];
                int l_time = landDuration[i];

                if (w_strt + w_time >= l_strt) {
                    ans = min(ans, w_strt + w_time + l_time);
                } else {
                    ans = min(ans, l_strt + l_time);
                }
            }
        }

        return ans;
    }
};