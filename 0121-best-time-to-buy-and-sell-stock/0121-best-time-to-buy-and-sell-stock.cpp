class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit=0;
       int min_element=prices[0];
       for(int i=0;i<prices.size();i++){
         min_element=min(min_element,prices[i]);
         profit=max(profit,prices[i]-min_element);
       } 
       return profit;
    }
};