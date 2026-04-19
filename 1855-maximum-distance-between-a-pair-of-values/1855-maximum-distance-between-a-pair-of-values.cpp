class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
       for(int i=0;i<n1;i++){
        int start=i;
        int end=n2-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums2[mid]>=nums1[i]){
                ans=max(ans,mid-i);
                // possible answer mil gya hai
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
       } 

       return ans;
    }
};