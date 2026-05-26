class Solution {
public:
   int n;
   int t[10001];
   bool recur(int idx,vector<int>&nums){
    if(idx>=n-1){
        return t[idx]= true;
    }
    if(t[idx]!=-1)return t[idx];
    for(int i=1;i<=nums[idx];i++){
        if(recur(idx+i,nums)){
            return t[idx]= true;
        };
    }

    return t[idx]=false;
   }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return recur(0,nums);
    }
};