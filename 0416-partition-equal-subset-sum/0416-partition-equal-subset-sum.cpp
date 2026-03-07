class Solution {
public:
    bool isSubsetSum(int idx,vector<int>&nums,int target){
        if(target==0){
            return true;
        }
        if(idx==nums.size()  && target !=0){
            return false;
        }
        bool take=isSubsetSum(idx+1,nums,target-nums[idx]);
        bool not_take=isSubsetSum(idx+1,nums,target);
        return take || not_take;
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return false; // not possible
        int target=sum/2;
      return isSubsetSum(0,arr, target);
        
    }
};