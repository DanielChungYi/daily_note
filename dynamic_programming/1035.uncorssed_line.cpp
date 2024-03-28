#include <glibc_wrapper.hpp>

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n_size1 = nums1.size() + 1;
        int n_size2 = nums2.size() + 1;
        vector<vector<int>> dp(n_size1, vector<int>(n_size2, 0));

        for(int i = 1; i < n_size1; i++) {
            for(int j = 1; j < n_size2; j++) {
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n_size1 - 1][n_size2 - 1];
    }
};

int main() {
    return 0;
}
