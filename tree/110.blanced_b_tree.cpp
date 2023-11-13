class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return  traversal(root) == -1 ? false : true;
    }

    int traversal(TreeNode* node) {
        if(!node) return 0;

        //left
        int l_depth = traversal(node->left);
        if(l_depth == -1) return -1;
        //right
        int r_depth = traversal(node->right);
        if(r_depth == -1) return -1;
        //mid
        if(abs(l_depth - r_depth) > 1) return -1;
        else return 1 + max(r_depth, l_depth);
        
    }
};