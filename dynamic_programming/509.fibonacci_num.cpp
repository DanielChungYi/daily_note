#include <glibc_wrapper.hpp>
class Solution {
public:
    int fib(int n) {
        int *dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        if(n <= 1) return dp[n];
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int result = dp[n];
        delete[] dp;
        return result;
    }
};

int main() {
    Solution s;
    std::cout << s.fib(5);
    return 0;
}
