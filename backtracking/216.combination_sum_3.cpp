class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return ans;
    }

    void backtracking(int k, int n, int sum, int start_index) {
        if(tmp.size() == k) {
            if(sum == n) {
                ans.push_back(tmp);
            }
            return;
        }

        for(int i=start_index; i<=9; i++) {
            sum += i;
            tmp.push_back(i);
            backtracking(k, n, sum, i+1);
            sum -= i;
            tmp.pop_back();
        }
    }
};