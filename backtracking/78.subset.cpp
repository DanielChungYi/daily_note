class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }

    void backtracking(vector<int>& nums, int start_index) {
        result.push_back(tmp);

        if(start_index >= nums.size()) return;

        for(int i = start_index; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtracking(nums, i + 1);
            tmp.pop_back();
        }
    }
};