class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> tmp;
        if(root == NULL) return ans;
        traversal(root, tmp, ans);
        return ans;
    }
    void traversal(TreeNode* node, vector<int>& tmp, vector<string>& ans) {
        tmp.push_back(node->val);
        
        // No nedd to travel to NULL like usual, 
        // collect result while reaching the leaf node
        if((node->left == NULL) && (node->right == NULL)){
            string s;
            for(const auto& e : tmp) {
                s += to_string(e);
                s += "->";
            }
            // Remove last "->"
            s.pop_back();s.pop_back();
            // Collect result
            ans.push_back(s);
            return;
        } 

        if(node->left) {
            traversal(node->left, tmp, ans);
            // This is where backtrack happens
            tmp.pop_back();
        }

        if(node->right) {
            traversal(node->right, tmp, ans);
            // This is where backtrack happens
            tmp.pop_back();
        }
    }
};