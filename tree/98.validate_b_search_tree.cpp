class Solution {
public:
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        return traversal(root);
    }

    bool traversal(TreeNode* n) {
        if(n == NULL) return true;
        
        // in-order
        // left
        bool l_result = traversal(n->left);
        // mid
        if(pre != NULL && pre->val >= n->val) {
            return false;
        }
        pre = n;
        // right
        bool r_result = traversal(n->right);

        return l_result && r_result;
    }
};