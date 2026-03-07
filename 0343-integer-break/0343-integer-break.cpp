class Solution {
public:
    int helper(int n){
        if(n==1)return 1; // further we cnt break
        int res=0;
        for(int j=1;j<n;j++){
          int product=j*max(n-j,helper(n-j));
          res=max(res,product);
        }
        return res;
    }
    int integerBreak(int n) {
        return helper(n);
    }
};