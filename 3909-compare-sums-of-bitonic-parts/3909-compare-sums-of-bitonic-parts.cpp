class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
       long long sumleft = 0;
        long long sumright = 0;
        int peak = 0;
        for (int i = 1; i < n-1; i++) {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
                peak = i;
                break;
            }
        }

        for(int i=0;i<=peak;i++){
            sumleft+=nums[i];
        }
        for(int j=peak;j<n;j++){
            sumright+=nums[j];
        }

        if(sumleft>sumright)return 0;
        else if(sumleft<sumright)return 1;
        return -1;
    }
};