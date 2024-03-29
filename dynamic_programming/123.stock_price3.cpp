#include <glibc_wrapper.hpp>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>>dp (prices.size(), vector<int>(5, 0));
        //dp[0] : Do nothing
        //dp[1] : First time to hold stocks
        //dp[2] : First time not to hold stocks
        //dp[3] : Second time to hold stocks
        //dp[4] : Second time not to hold stocks
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];

        for(int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);          
        }
        return dp[prices.size() -1][4];

    }
};
int main() {
    return 0;
}
