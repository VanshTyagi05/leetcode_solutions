class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ans(n + 1);
        ans[0] = 0;
        int sum=0;
        int maxi=0;
        for (int i = 0; i < n; i++) {
            sum+=gain[i];
            ans[i+1]=sum;
            maxi=max(maxi,ans[i+1]);
        }
        return maxi;
    }
};