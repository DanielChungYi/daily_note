#include <glibc_wrapper.hpp>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        int target = sum/2;
        vector<int> dp(target + 1, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = target; j >= nums[i]; j--) {
		// the capacity of backpack should be greater than the nums[I] weight
               dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return (dp[target] == target) ? true : false;
    }
};

int main() {
    return 0;
}
