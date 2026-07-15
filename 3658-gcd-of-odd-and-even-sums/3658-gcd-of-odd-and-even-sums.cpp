class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;
        for(int i=1;i<=2*n;i++){
            if(i%2==0){
                //even
               sumEven+=i;
            }else{
                sumOdd+=i;
            }
        }

        return gcd(sumEven,sumOdd);
    }
};