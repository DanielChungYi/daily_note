class Solution {
public:
    int maxDepth(TreeNode* root) {
        return travsersal(root);
    }
    
    int travsersal(TreeNode* node) {
        if(node == NULL) return 0;
        int l_depth = travsersal(node->left);
        int r_depth = travsersal(node->right);
        int result = 1 + max(l_depth, r_depth);
        return result;
    }
};