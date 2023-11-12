class Solution {
public:
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }

    void traversal(TreeNode* n, vector<int> &v) {
        if(!n) return;
        v.push_back(n->val);
        traversal(n->left, v);
        traversal(n->right, v); 
    }
};

