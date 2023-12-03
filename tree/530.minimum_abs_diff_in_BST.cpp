class Solution {
public:
    TreeNode* pre = NULL;
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        traversal(root, result);
        return result;
    }

    void traversal(TreeNode* n, int& result) {
        if(!n) return;

        // in-order
        // left
        traversal(n->left, result);
        // mid
        if(pre != NULL) {
            result = min(result, n->val - pre->val);
        }
         pre = n;
        // right
        traversal(n->right, result);

        return;
    }
};