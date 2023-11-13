class Solution {
public:
    int minDepth(TreeNode* root) {
        return traversal(root);
    }

    int traversal(TreeNode* node) {
        if(node == NULL) return 0;

	//left
        int l_depth = traversal(node->left);  

	//right
        int r_depth = traversal(node->right); 
	
	// mid
	// Check if the node has completed two childs
        if((node->left == NULL) && (node->right != NULL)) {
            return 1 + r_depth;
        }
        if((node->left != NULL) && (node->right == NULL)) {
            return 1 + l_depth;
        }
        return 1 + min(l_depth, r_depth);
    }
};