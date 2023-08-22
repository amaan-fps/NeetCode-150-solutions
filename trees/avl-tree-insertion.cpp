//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

int height(Node* n)
{
    if(!n)
        return 0;
    return n->height;
}

int balanceFactor(Node* n)
{
    if(!n)
        return 0;
    return height(n->left) - height(n->right);
}

Node* LLRotation(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;
    
    pl->right = p;
    p->left = plr;
    
    p->height = 1 + max(height(p->left), height(p->right));
    pl->height = 1 + max(height(pl->left), height(pl->right));
    
    return pl;
}

Node* RRRotation(Node* p)
{
    Node* pr = p->right;
    Node* prl = pr->left;
    
    pr->left = p;
    p->right = prl;
    
    p->height = 1 + max(height(p->left), height(p->right));
    pr->height = 1 + max(height(pr->left), height(pr->right));
    
    return pr;
}

Node* LRRotation(Node* p)
{
    Node* pl = p->left;
    Node* plr = pl->right;
    
    p->left = plr->right;
    pl->right = plr->left;
    
    plr->right = p;
    plr->left = pl;
    
    p->height = 1 + max(height(p->left), height(p->right));
    pl->height = 1 + max(height(pl->left), height(pl->right));
    plr->height = 1 + max(height(plr->left), height(plr->right));
    
    return plr;
}

class Solution{
  public:
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(node == NULL)
            return new Node(data);
            
        if(data < node->data)
            node->left = insertToAVL(node->left, data);
        else if(data > node->data)
            node->right = insertToAVL(node->right, data);
        else
            return node;
            
        node->height = 1 + max(height(node->left), height(node->right));
        
        int balance = balanceFactor(node);
        int left_child_balance = balanceFactor(node->left);
        int right_child_balance = balanceFactor(node->right);
        
        if(balance == 2 && left_child_balance == 1)
            return LLRotation(node);
        else if(balance == 2 && left_child_balance == -1)
            return LRRotation(node);
        else if(balance == -2 && right_child_balance == -1)
            return RRRotation(node);
        else if(balance == -2 && right_child_balance == 1)
        {
            node->right = LLRotation(node->right);
            return RRRotation(node);
        }
        
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends
