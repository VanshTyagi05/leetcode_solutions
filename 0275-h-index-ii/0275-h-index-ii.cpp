class Solution {
public:
    int hIndex(vector<int>& citations) {
        int total=citations.size();
        int start=0;
        int end=total-1;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            // current paper ki h citations hai
            int h=citations[mid];
            if(h>=total-mid){
                ans=max(ans,total-mid);
                end=mid-1;
            }else{
                start=mid+1;
            }

        }
        return ans;
    }
};