class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        // going with approach 1
        // land ->then wtaer so find the land ride that finished the first
        int l_finish=INT_MAX;
        for(int i=0;i<n;i++){
           l_finish=min(l_finish,landStartTime[i]+landDuration[i]);
        }
        // now try all the rides in the water
        for(int j=0;j<m;j++){
            int maxi=max(l_finish,waterStartTime[j]);
            ans=min(ans,maxi+waterDuration[j]);
        }


        /// now trying the approach two i.e going water first and then land
        int w_finish=INT_MAX;
        for(int i=0;i<m;i++){
           w_finish=min(w_finish,waterStartTime[i]+waterDuration[i]);
        }
        // now try all the rides in the land
        for(int j=0;j<n;j++){
            int maxi=max(w_finish,landStartTime[j]);
            ans=min(ans,maxi+landDuration[j]);
        }

        return ans;
        }
};