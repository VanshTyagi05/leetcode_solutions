class Solution {
public:
    void append(vector<int>&ans,int num){
        while(num>0){
            ans.push_back(num%10);
            num/=10;
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
           append(ans,nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};