class Solution {
public:
    int maxCount = 0; 
    int count = 0; 
    TreeNode* pre = NULL;
    vector<int> result;

    vector<int> findMode(TreeNode* root) {
        result.clear();

        travseral(root);
        return result;
    }

    void travseral(TreeNode* n) {
        // DFS
        // in-order
        if (n==NULL) return;

        travseral(n->left);
        // mid
        if(pre == NULL) {
            count = 1;
        } else if (pre->val == n->val) {
            count++;
        } else {
            count = 1;
        }
        pre = n;

        if(count == maxCount) {
            result.push_back(n->val);
        }
        if (count > maxCount) { 
            maxCount = count;   
            result.clear();     
            result.push_back(n->val);
        }

        travseral(n->right);
    }
};