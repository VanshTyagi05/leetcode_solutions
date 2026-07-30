class Solution {
public:
    int minimumPushes(string word) {
        int remaining=word.size();
        int group=1;
        int ans=0;
        while(remaining>0){
            if(remaining>8){
                ans=ans+(8*group);
                remaining-=8;
            }else{
               ans=ans+(remaining*group);
               remaining=0;
            }
            group++;
        }

        return ans;
    }
};