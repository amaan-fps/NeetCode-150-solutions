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
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &indexMap, int &preIndex, int start, int end)
    {
        if(start > end)
            return NULL;

        int rootvalue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootvalue);

        root->left = build(preorder, inorder, indexMap, preIndex, start, indexMap[rootvalue]-1);
        root->right = build(preorder, inorder, indexMap, preIndex, indexMap[rootvalue]+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> indexMap;
        int i = 0;
        for(int x : inorder)
            indexMap[x] = i++;
        int preIndex = 0;
        return build(preorder, inorder, indexMap, preIndex, 0, inorder.size()-1);
    }
};
