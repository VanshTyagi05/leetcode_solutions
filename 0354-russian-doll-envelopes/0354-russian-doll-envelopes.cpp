class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size(); // bhaii iska concept same hai longest increasing subsequence jaisa
        vector<int>dp(n,1); // always possible
        auto lamda=[](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return a[1]>b[1]; // agr widhth same hai toh height ko descending order mai sort krod bhaii iska logic bhou khtrnaak hai
            }
            return a[0]<b[0];
        };
        sort(envelopes.begin(),envelopes.end(),lamda);

        // now we wil be writing the logic similar to los
        // bhaii ab bas height par LIS laga do i.e pateince sorting vala tarika
        vector<int>lis;
        for(int i=0;i<n;i++){
            int h=envelopes[i][1];
            auto it=lower_bound(begin(lis),end(lis),h);
            if(it==end(lis)){
                lis.push_back(h);
            }else{
                *it=h;
            }
        }
        

        return lis.size();
    }
};