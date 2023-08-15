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
// bigger code
class Solution {
public:
    int dfs(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return 1;
        if(!p || !q) return -1;

        int left = dfs(p->left, q->left);
        if(left == -1)
            return -1;
        
        int right = dfs(p->right, q->right);
        if(right == -1)
            return -1;

        if(p->val != q->val)
            return -1;
        
        return 1;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q) != -1;
    }
};

// same work but clean code
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && (p->val == q->val);
    }
};
