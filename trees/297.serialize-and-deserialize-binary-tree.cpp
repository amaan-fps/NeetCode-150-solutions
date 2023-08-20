/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string &s)
    {
        if(!root)
        {
            s.push_back('N');
            s.push_back(',');
            return;
        }

        s = s + to_string(root->val);
        s.push_back(',');

        dfs(root->left, s);
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {
        
        string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* build(string &preorder, int &i)
    {
        if(preorder[i] == 'N')
        {
            i += 2;
            return NULL;
        }    

        string temp;
        while(preorder[i++] != ',')
            temp.push_back(preorder[i-1]);
            
        int rootvalue = stoi(temp);
        TreeNode* root = new TreeNode(rootvalue);
        
        root->left = build(preorder, i);
        root->right = build(preorder, i);

        return root;
    }

    TreeNode* deserialize(string preorder) {
        
        int index = 0;
        return build(preorder, index);
    }
};


class cleanDecode {
public:
    // Encodes a tree to a single string.
    void dfs(TreeNode* root, string &s)
    {
        if(!root)
        {
            s.push_back('N');
            s.push_back(',');
            return;
        }

        s = s + to_string(root->val);
        s.push_back(',');

        dfs(root->left, s);
        dfs(root->right, s);
    }

    string serialize(TreeNode* root) {
        
        string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* build(vector<string> &nodes, int &i)
    {
        if(nodes[i] == "N")
        {
            i += 1;
            return NULL;
        }
            
        int rootvalue = stoi(nodes[i++]);
        TreeNode* root = new TreeNode(rootvalue);
        
        root->left = build(nodes, i);
        root->right = build(nodes, i);

        return root;
    }

    TreeNode* deserialize(string preorder) {
        
        vector<string> nodes;
        istringstream stream(preorder);
        string token;

        while(getline(stream, token, ','))
            nodes.push_back(token);

        int index = 0;
        return build(nodes, index);
    }
};
