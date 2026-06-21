class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>freq(100001,0);
        for(int num:costs){
            freq[num]++;
        }
        int ans=0;
        for(int cost=1;cost<=100000;cost++){
            while(freq[cost]>0 && coins>=cost){
               coins-=cost;
               freq[cost]--;
               ans++;
            }

            if(coins<cost){
                break;
            }
        }

        return ans;
    }
};