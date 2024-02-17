#include <glibc_wrapper.hpp>

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        // dp[i][0] : Maximum cash we had to hold stock on day i
        // dp[i][1] : Maximum cash we had to NOT hold stock on day i

        dp[0][0] = -prices[0];

        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }

        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};

int main() {
    return 0;
}
