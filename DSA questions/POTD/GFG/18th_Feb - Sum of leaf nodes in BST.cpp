// Sum of leaf nodes in BST
// https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1

class Solution
{
    int sumLeafNodes(Node* root){
        if(!root)   return 0;
        
        if(!root->left && !root->right)  // if leaf node, return its value
            return root->data;
            
        return sumLeafNodes(root->left) + sumLeafNodes(root->right);  // Otherwise, recursively sum the leaf nodes in the left and right subtrees
    }
    public:
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
            return sumLeafNodes(root);
        }
};
