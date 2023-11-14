
// Breadth First Search
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr) return 0;
        q.push(root);
        int ans;
        while(!q.empty()) {
            int size = q.size();
            ans = q.front()->val;
            while(size--) {
                TreeNode* tmp = q.front();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                q.pop();
            }
        }
        return ans;
    }
};

// Depth First Search
class Solution {
public:
    int maxdepth = INT_MIN;
    int val = 0;
    int dep = 0;

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, dep);
        return val;
    }

    void traversal(TreeNode* n, int& depth) {
        if(!n->left && !n->right) {
            if(depth > maxdepth) {
                val = n->val;
                maxdepth = depth;
            }
        }

        //left
        if(n->left) {
            depth++;
            traversal(n->left, depth);
            depth--;
        }
        //right
        if(n->right) {
            depth++;
            traversal(n->right, depth);
            depth--;
        }
    }
};