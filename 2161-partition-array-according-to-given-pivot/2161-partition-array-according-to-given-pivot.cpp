class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller,equal,larger;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                smaller.push_back(nums[i]);
            }else if(nums[i]==pivot){
                equal.push_back(pivot);
            }else{
                larger.push_back(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<smaller.size();i++){
            ans.push_back(smaller[i]);
        }
        for(int i=0;i<equal.size();i++){
            ans.push_back(equal[i]);
        }
        for(int i=0;i<larger.size();i++){
            ans.push_back(larger[i]);
        }

        return ans;
    }
};