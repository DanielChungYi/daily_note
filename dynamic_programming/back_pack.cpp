#include <glibc_wrapper.hpp>

void bp(vector<int> weight, vector<int> value, int bag_weight) {
    vector<vector<int>> dp(value.size(), vector<int>(bag_weight + 1, 0));
    for(int j = weight[0]; j <= bag_weight; j++) {
        dp[0][j] = value[0];
    }

    for(int i = 1; i < weight.size(); i++) {
        for(int j = 0; j <= bag_weight; j++) {
            if(weight[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight[j]] + value[i]); 
        }
    }

    PRINT_2D_VECTOR_ELEMENTS(dp);
}
int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20 ,30};
    bp(weight, value, 4);
    return 0;
}
