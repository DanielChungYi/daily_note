#include <glibc_wrapper.hpp>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        // Init
        // dp[i][0] : Holding stocks on day i
        // dp[i][1] : Not holding stock on day i
        // dp[i][2] : Actually sell the stock on day i
        // dp[i][3] : Cooldown on day i
        dp[0][0] -= prices[0];
        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(max(dp[i-1][0], dp[i-1][1] - prices[i]), dp[i-1][3] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(max(dp[prices.size()-1][2], dp[prices.size()-1][3]), dp[prices.size()-1][1]);
    }
};

int main() {
    return 0;
}
