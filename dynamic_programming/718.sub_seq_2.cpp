#include <glibc_wrapper.hpp>

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int size_1 = nums1.size() + 1;
        int size_2 = nums2.size() + 1;
        int result = 0;

        vector<vector<int>> dp(size_1, vector<int>(size_2, 0));

        for(int i = 1; i < size_1; i++) {
            for(int j = 1; j < size_2; j++) {
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > result) result = dp[i][j];
            } 
        }
        
        return result;
    }
};


int main() {
    return 0;
}
