#include <glibc_wrapper.hpp>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int result = 0;
       
        for(int i = 1; i < nums.size(); i++) { 
            int cnt = 0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) dp[i] = max(dp[j] + 1, dp[i]);
            }
            if(dp[i] > result) result = dp[i];
        }

        return result;
    }
};

int main() {
    return 0;
}
