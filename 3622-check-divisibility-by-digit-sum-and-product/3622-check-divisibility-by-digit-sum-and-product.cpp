class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int sum=0;
        int product=1;
        while(temp>0){
           int rem=temp%10;
           sum+=rem;
           product*=rem;
           temp/=10;
        }
        return n%(sum+product)==0;
    }
};