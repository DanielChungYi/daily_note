#include <glibc_wrapper.hpp>

template <typename T>
void print_dp(vector<vector<T>>& dp) {
    cout << "Dump dp table\n";
    for(const auto row : dp) {
        for(const auto value : row) {
            cout << value << ",";
        }
        cout << endl;
    }
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; i++) { dp[i][0] = 1; }
        for(int i = 0; i < n && obstacleGrid[0][i] == 0; i++) { dp[0][i] = 1; }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n ; j++) {
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        print_dp(dp);
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> input = { {0, 1}, {0, 0}};
    Solution s;
    s.uniquePathsWithObstacles(input); 
    vector<vector<int>> input2 = { {0} };
    s.uniquePathsWithObstacles(input2); 
    return 0;
}
