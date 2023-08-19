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
    int dfs(TreeNode* root, int &maxSum)
    {
        if(!root) return 0;

        int left = dfs(root->left, maxSum);
        int right = dfs(root->right, maxSum);
        
        int sum = left + right + root->val;
        if(sum >= maxSum)
            maxSum = sum;
        
        int maxPath = (max(left, right) + root->val) > root->val ? (root->val + max(left, right)) : root->val;
        maxSum = max(maxSum, maxPath);
        
        return maxPath;
    }

    int maxPathSum(TreeNode* root) {
        
        int maxSum = 0-1001;
        dfs(root, maxSum);
        return maxSum;
    }
};
