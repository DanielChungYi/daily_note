class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, used, 0);
        return result;

    }

    void backtracking(const vector<int>& nums, vector<bool>& used, int start_index) {
        result.push_back(tmp);
        if(start_index >= nums.size()) return;

        for(int i = start_index; i < nums.size(); i++) {
            if(i > 0 && nums[i-1] == nums[i] && used[i-1] == false) {
                continue;
            }
            used[i] = true;
            tmp.push_back(nums[i]);
            backtracking(nums, used, i+1);
            used[i] = false;
            tmp.pop_back();
        }
    }

    
};