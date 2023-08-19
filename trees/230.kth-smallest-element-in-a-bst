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
    int res, count = 0;
    int dfs(TreeNode* root, int k)
    {
        if(!root) return 0;

        int left = dfs(root->left, k);
        count += 1;
        if(count == k)
            res = root->val;
        int right = dfs(root->right, k);

        return 1+left+right;
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
