class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        int m1,m2; //current size of arr1 and arr2
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        m1=1;
        arr2.push_back(nums[1]);
        m2=1;
        for(int i=2;i<n;i++){
            if(arr1[m1-1]>arr2[m2-1]){
                arr1.push_back(nums[i]);
                m1++;
            }else{
                arr2.push_back(nums[i]);
                m2++;
            }
        }
        vector<int>result;
        for(int i=0;i<m1;i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<m2;i++){
            result.push_back(arr2[i]);
        }
        return result;
        
    }
};