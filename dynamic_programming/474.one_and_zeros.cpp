#include <glibc_wrapper.hpp>
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        int ans;
        for(string s : strs) {
            int x = 0;
            int y = 0;
            for(char c : s) {
                if(c == '0') x++;
                else y++;
            }
            for(int i = m; i >= x; i--) {
                for(int j = n; j >= y; j--) {
                    dp[i][j] = max(dp[i-x][j-y] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    return 0;
}
