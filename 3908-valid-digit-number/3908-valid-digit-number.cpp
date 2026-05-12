class Solution {
public:
    bool validDigit(int n, int x) {
        bool hasx=false;
        bool strting=true;
        while(n>0){
            int num=n%10;
            if(num==x)hasx=true;
            n/=10;
            if(n==0){
                // iska mtlb h num last number tha
                if(num==x){
                    strting=false;
                }
            }
        }

        return hasx && strting;
    }
};