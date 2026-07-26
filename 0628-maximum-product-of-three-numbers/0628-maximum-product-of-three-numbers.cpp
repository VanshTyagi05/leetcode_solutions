class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // count the negative numbers
        int neg=0;
        for(int i=0;i<3;i++){
            if(nums[i]<0){
                neg++;
            }
        }

        // now if neg==0
        if(neg==0){
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
        int num1=nums[n-1]*nums[n-2]*nums[n-3]; // teeno largest
        int num2=nums[0]*nums[1]*nums[1];
        int num3=nums[0]*nums[1]*nums[n-1]; // sabse chote do ek bada
        int num4=nums[0]*nums[n-1]*nums[n-2];

        return max({num1,num2,num3,num4}); 
    }
};