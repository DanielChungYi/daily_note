#include <glibc_wrapper.hpp>

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for(int i = 0; i <= s.size(); i++) { //backpack
            for(int j = 0; j < i; j++) { //items
                string word = s.substr(j, i - j);
                if(wordSet.find(word) != wordSet.end() && dp[j]) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }

};

int main() {
    return 0;
}
