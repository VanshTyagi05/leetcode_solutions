class Solution {
public:
   int findproduct(int n){
    int ans=1;
    while(n>1){
        ans=ans*(n%10);
        n/=10;
    }
    return ans;
   }
    int smallestNumber(int n, int t) {
        int start=n;
        int end=100;
        int ans=1;
        for(int i=start;i<=end;i++){
            if(findproduct(i)%t==0)return i;
        }
        return 0;
    }
};