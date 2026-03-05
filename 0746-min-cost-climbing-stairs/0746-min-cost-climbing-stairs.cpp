class Solution {
public:
    int fun(int idx,vector<int>&cost){
        if(idx>=cost.size()){
            return 0; // we have reached the top
        }
        //first cvhoice climb only ne step
        int onestep=cost[idx]+fun(idx+1,cost);
        int twostep=cost[idx]+fun(idx+2,cost);
        return min(onestep,twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int strting0=fun(0,cost);
        int strting1=fun(1,cost);
        return min(strting0,strting1);
    }
};