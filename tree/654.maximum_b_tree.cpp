class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }

    TreeNode* traversal(vector<int> &nums, int l_index, int r_index) {
        if(l_index >= r_index) return NULL;

        // mid
        int max_index = l_index;
        for (int i = l_index + 1; i < r_index; ++i) {
            if (nums[i] > nums[max_index]) max_index = i;
        }
        TreeNode* n = new TreeNode(nums[max_index]);
        

        // left
        // include low boundary, exclude high boundary
        
        n->left  = traversal(nums, l_index, max_index);

        // right
        // include low boundary, exclude high boundary

        n->right  = traversal(nums, max_index + 1, r_index);
        

        return n;
    }
};