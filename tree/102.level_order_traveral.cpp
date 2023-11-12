#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> vec;
            while(size--) {
                TreeNode* tmp = queue.front();
                queue.pop();
                vec.push_back(tmp->val);
                if(tmp->left) queue.push(tmp->left);
                if(tmp->right) queue.push(tmp->right);
            }
            ans.push_back(vec);
        }
        return ans;

    }

};


