class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root);
    }

    int traversal(TreeNode* n) {
        if(n == NULL) return 0;
        
	// Post order
        // left
        int l_val = traversal(n->left);
        if((n->left != NULL) && (n->left->right == NULL) && (n->left->left == NULL)) {
            l_val = n->left->val;
        }
	
	// right
        int r_val = traversal(n->right);

	// mid
        return l_val + r_val;
        
    }
};