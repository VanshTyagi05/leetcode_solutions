class Solution {
public:
   int n;
   int t[10001];
    int recur(int idx,vector<int>&nums,int steps){
        if(idx>=n-1){
            return 0;
        }
        if(t[idx]!=-1)return t[idx];
        int curr_steps=1e9;
        for(int i=1;i<=nums[idx];i++){
            curr_steps=min(curr_steps,1+recur(idx+i,nums,steps+1));
        }
        return t[idx]=curr_steps;
    }
    int jump(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return recur(0,nums,0);
    }
};