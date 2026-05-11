class Solution {
public:
     bool count(int num){
        long sum=0;
        while(num>0){
            sum+=(num%10);
            num/=10;
        }
        return sum%2==0;
     }
    int countEven(int num) {
        int ans=0;
        for(int i=1;i<=num;i++){
            if(count(i)){
                ans++;
            }
        }
        return ans;
    }
};