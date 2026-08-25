class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int num=k;
        set st(nums.begin(),nums.end());
        while(true){
          if(st.contains(num)==false){
            return num;
          }
          num=num+k;
        }
        return -1;
    }
};