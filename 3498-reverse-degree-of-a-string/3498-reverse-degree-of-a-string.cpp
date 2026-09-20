class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            int curr='z'-c+1;
            sum+=((i+1)*curr); 
        }
        return sum;
    }
};