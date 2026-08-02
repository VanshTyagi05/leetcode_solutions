class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int start=0;
        int end=n-1; 
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        int turn=1;//1->ALice 
                   //0->Bob
        int alice=0;//sum for alice
        int bob=0;//sum for bob
        while(start<=end){
            if(piles[start]>=piles[end]){
              if(turn){
                alice+=piles[start];
                start++;
              }else{
                bob+=piles[start];
                start++;
              }
            }else{
                if(turn){
                alice+=piles[end];
                end--;
              }else{
                bob+=piles[end];
                end--;
              }
            }

            // if at any point 
            if(alice>(sum/2))return true;
        }
        return false;
    }
};