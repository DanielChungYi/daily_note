#include <glibc_wrapper.hpp>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(const auto i : nums) {
            sum += i ;
        }
        int bag_size = (sum + target) / 2;
        if((sum + target) % 2 == 1) return 0;
        if(abs(target) > sum) return 0;

        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = bag_size; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bag_size];
    }
};

int main() {
    return 0;
}
