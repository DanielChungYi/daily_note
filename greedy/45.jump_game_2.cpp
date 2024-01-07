class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int cur_dis = 0;
        int next_dis = 0;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            next_dis = max(nums[i] + i, next_dis);
            if(i == cur_dis) {
                result++;
                cur_dis = next_dis;
                if(next_dis >= nums.size() - 1) break;
            }
        }
        return result;
    }
};