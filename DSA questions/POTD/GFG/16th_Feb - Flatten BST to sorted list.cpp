// Flatten BST to sorted list
// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

class Solution
{
    void inorder(Node* root, vector<Node*> &res){
        if(!root)   return;
        
        inorder(root->left,res);
        res.push_back(root);
        inorder(root->right,res);
    }
public:
    Node *flattenBST(Node *root)
    {
        if(!root)   return root;
        
        vector<Node*> res;
        inorder(root,res);
        
        for(int i = 0;i<res.size()-1;i++){
            res[i]->left = NULL;
            res[i]->right = res[i+1];
        }
        
        res.back()->left = nullptr; // Ensure last node's left pointer is NULL
        
        return res[0];
      
    }
};
