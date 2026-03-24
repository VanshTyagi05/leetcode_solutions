class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd=INT_MAX;
        bool odd=false;
        for(int num:nums1){
           if(num%2!=0){
            odd=true;
            min_odd=min(min_odd,num);
           }
        }
        if(!odd)return true; // case of all even elements
        for(int num:nums1){
            if(num%2==0 && min_odd>num)return false;
        }
        return true;
    }
};