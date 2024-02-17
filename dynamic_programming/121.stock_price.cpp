#include <glibc_wrapper.hpp>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        //dp[i] 0: maximum cash with stocks
        //dp[i] 1: maximum cash without stocks
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], - prices[i]);
            dp[i][1] = max(dp[i-1][0] + prices[i], dp[i-1][1]);
        }

        return dp[prices.size() - 1][1];
    }
};

int main() {
    return 0;
}
