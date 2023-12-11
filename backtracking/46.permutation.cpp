class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        tmp.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }

    void backtracking(vector<int>& nums, vector<bool>& used) {
        if(tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        } 

        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == true) continue;
            used[i] = true;
            tmp.push_back(nums[i]);
            backtracking(nums, used);
            tmp.pop_back();
            used[i] = false;
        }
    }
};
