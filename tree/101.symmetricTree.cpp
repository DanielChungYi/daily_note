
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return travseral(root->left, root->right);
    }

    bool travseral(TreeNode* lnode, TreeNode* rnode) {
        
        if((lnode  == nullptr) && (rnode != nullptr)) return false;
        else if((lnode != nullptr) && (rnode == nullptr)) return false;
        else if((lnode == nullptr) && (rnode == nullptr)) return true;
        else if( lnode->val != rnode->val ) return false;
        
        bool ans1 = travseral(lnode->left, rnode->right);
        bool ans2 = travseral(lnode->right, rnode->left);

        return ans1 && ans2;

        
    }
};