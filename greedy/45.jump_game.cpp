class Solution {
public:
    int cover = 0;
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        cover = nums[0];
        for(int i = 0; i <= cover; i++) {
            cover = max(nums[i] + i, cover);
            if(i == nums.size() - 1) return true;
        }
        return false;      
    }
};