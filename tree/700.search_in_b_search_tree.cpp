class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) {
            return root;
        }
        TreeNode* result;
        if(val < root->val) {
            result = searchBST(root->left, val);
        }
        if(val > root->val) {
            result = searchBST(root->right, val);
        }
        return result;
    }
};