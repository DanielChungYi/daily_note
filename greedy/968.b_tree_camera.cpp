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
/*
enum node_type {
    no_cover,
    with_cam,
    covered
};
*/

class Solution {
public:
    int result = 0;
    int minCameraCover(TreeNode* root) { 
        if(traversal(root) == 0) {
            result++;
        }
        return result;
    }

    int traversal(TreeNode* node) {
        if(node == NULL) {
            return 2;
        }

        int lv = traversal(node->left);
        int rv = traversal(node->right);
        
        if(lv == 2 && rv == 2) return 0;
        if(lv == 0 || rv == 0) {
            result++;
            return 1;
        }
        if (lv == 1 || rv == 1) return 2;
        return -1;
    }
};
