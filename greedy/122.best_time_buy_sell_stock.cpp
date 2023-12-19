class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int pre = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - pre;
            if(profit > 0) {
                result += profit;
            }
            pre = prices[i];
        }
        return result;
    }
};