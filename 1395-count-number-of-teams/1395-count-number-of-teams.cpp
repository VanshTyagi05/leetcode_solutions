class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        int n = rating.size();
        for (int j = 1; j < n - 1; j++) {
            int count_left_asc = 0;
            int count_right_asc = 0;
            int count_left_dsc = 0;
            int count_right_dsc = 0;
            // jth is the middle element
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    count_left_asc++;
                }
                if (rating[i] > rating[j]) {
                    count_left_dsc++;
                }
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[j] < rating[k]) {
                    count_right_asc++;
                }
                if (rating[j] > rating[k]) {
                    count_right_dsc++;
                }
            }
            // Ascending teams: (smaller on left) * (larger on right)
            ans += (count_left_asc * count_right_asc);

            // Descending teams: (larger on left) * (smaller on right)
            ans += (count_left_dsc * count_right_dsc);
        }

        return ans;
    }
};