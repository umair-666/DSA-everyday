// Count the nodes at distance K from leaf
// https://www.geeksforgeeks.org/problems/node-at-distance/1

class Solution
{
    void helper(Node* root,int k,set<int> &s,int i,int n){
        if(root==NULL)      return ;
        
        if( !root->left && !root->right && i==k)
            s.insert(n);
        
        helper(root->left, k, s, i+1, n);
        helper(root->right, k, s, i+1, n);
        
    }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
        set<int> s;     
        if(!root)   return s.size();
        
        helper(root, k, s, 0, root->data);
        
        int leftResult = printKDistantfromLeaf(root->left, k);
        int rightResult = printKDistantfromLeaf(root->right, k);
        
        return s.size() + leftResult + rightResult;
    }
};
