class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n);
        vector<int>sorted;
        for(int i=0;i<n;i++){
            auto it=upper_bound(begin(sorted),end(sorted),obstacles[i]);
            int pos=it-sorted.begin();
            if(it==end(sorted)){
                sorted.push_back(obstacles[i]);
            }else{
                *it=obstacles[i];
            }

            ans[i]=pos+1;
            
        }

        return ans;
    }
};