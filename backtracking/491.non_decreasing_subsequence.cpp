class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }

    void backtracking(const vector<int>& nums, int start_index) {
        if(path.size() > 1) {
            result.push_back(path);
        }
        unordered_set<int> uset; 
        for(int i = start_index; i < nums.size(); i++) {
            if( !path.empty() && nums[i] < path.back() || uset.find(nums[i]) != uset.end()) {
                continue;
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back();
        }
    }
};