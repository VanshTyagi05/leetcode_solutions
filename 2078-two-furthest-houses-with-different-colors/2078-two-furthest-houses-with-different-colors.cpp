class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            // selecting the ith 
            int color1=colors[i];
            for(int j=i+1;j<n;j++){
                int color2=colors[j];
                if(color1!=color2){
                    ans=max(ans,abs(i-j));
                }
            }
        }
        return ans;
    }
};