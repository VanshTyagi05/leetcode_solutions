class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int num1=nums[n-1]*nums[n-2]*nums[n-3]; // teeno largest lelo
        //int num2=nums[0]*nums[1]*nums[2]; // teeno sabse chote dekh lo (2 ngative hue aur 1 positive)
        int num3=nums[0]*nums[1]*nums[n-1]; // sabse chote do ek bada
        //int num4=nums[0]*nums[n-1]*nums[n-2]; // ek sabse chota aur do sabse bade

        return max({num1,num3}); 
    }
};