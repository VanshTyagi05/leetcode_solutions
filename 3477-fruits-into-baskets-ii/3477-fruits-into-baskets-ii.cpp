class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = n;
        for (int i = 0; i < n; i++) {

            int curr_fruit = fruits[i];
            for (int j = 0; j < n; j++) {
                if (baskets[j] >= curr_fruit) {
                    baskets[j]=-1;
                    ans--;
                    break;
                }
            }
        }
        return ans;
    }
};