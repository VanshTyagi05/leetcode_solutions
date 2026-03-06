class Solution {
public:
    int solve(vector<int>& prices, int day, bool buy) {
        if (day>= prices.size())
            return 0;

        int profit = 0;
        if (buy) {
            // agr aaj buy kr skte ho
            // -> toh do cases hai
            // ya toh buy krliya
            // ab yha hm profit dekh rhe hai kitna hoga agr aaj buy kre aur in
            // fututre sell kre
            int buy_karliya = solve(prices, day + 1, false) - prices[day];
            // ya phir buy nhi kiya
            int buy_nahiKiya = solve(prices, day + 1, true);
            profit = max(profit, max(buy_karliya, buy_nahiKiya));
        } else {
            // aaj sell kr skte hai
            // ya toh sell kiya
            // aur aaj agr sell kiya toh aage khareed bhi skte ho lekin day+2 pe
            // khareed skte ho
            int sell = prices[day] + solve(prices, day + 2, true);
            int not_sell = solve(prices, day + 1, false);
            profit = max(profit, max(sell, not_sell));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,true);
    }
};