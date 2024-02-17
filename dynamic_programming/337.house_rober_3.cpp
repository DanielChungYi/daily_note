#include <glibc_wrapper.hpp>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = traversal(root);
        return max(res[0], res[1]);
    }

    vector<int> traversal(TreeNode* root) {
        if(root == NULL) {
            return vector<int>{0, 0};
        }
        vector<int> left = traversal(root->left);
        vector<int> right = traversal(root->right);

        // Don't rob cur
        int cur0 = max(left[0], left[1]) + max(right[0], right[1]);

        // Rob cur
        int cur1 = left[0] + right[0] + root->val;

        return vector<int> {cur0, cur1};
    }
};
int main() {
    return 0;
}
