class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used, 0);
        return result;
    }

    void backtracking(const vector<int>& candidates, int target, int sum, vector<bool>& used, int start_index) {
        if(sum == target) {
            result.push_back(tmp);
            return;
        }
        
         for(int i=start_index; i < candidates.size() && sum + candidates[i] <= target; i++) {
             if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
             }
             
             sum += candidates[i];
             tmp.push_back(candidates[i]);
             used[i] = true;

             backtracking(candidates, target, sum, used, i+1);
             
             
             used[i] = false;
             sum -= candidates[i];
             tmp.pop_back();
         }
    }
};
