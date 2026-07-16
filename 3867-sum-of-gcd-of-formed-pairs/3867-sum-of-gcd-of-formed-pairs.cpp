class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>maxith(n);
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            maxith[i]=maxi;
        }
        vector<int>prefixGcd(n);
        for(int i=0;i<n;i++){
            prefixGcd[i]=gcd(nums[i],maxith[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int start=0;
        int end=n-1;
        long long sum=0;
        while(start<=end){
            if(start==end){
                break;
            }
           int num1=prefixGcd[start];
           int num2=prefixGcd[end];
           sum+=gcd(num1,num2);
            start++;
            end--;
        }
        return sum;
    }
};