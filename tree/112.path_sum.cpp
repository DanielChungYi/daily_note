class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return traversal(root, targetSum - root->val);
    }

    bool traversal(TreeNode* n, int sum) {
        // Abort condition
        if(!n->left && !n->right && sum == 0) {
            return true;
        } 
        if(!n->left && !n->right && sum != 0) {
            return false;
        } 

        // left
        if(n->left) {
            sum -= n->left->val;
            if(traversal(n->left, sum)) return true;
            sum += n->left->val;
        }
        // right
        if(n->right) {
            sum -= n->right->val;
            if(traversal(n->right, sum)) return true;
            sum += n->right->val;
        }

        return false;
    }
};