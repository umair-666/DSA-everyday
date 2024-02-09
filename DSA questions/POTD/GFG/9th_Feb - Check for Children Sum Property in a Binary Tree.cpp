// Check for Children Sum Property in a Binary Tree
// https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    { 
     if(!root)  return true;
     
        
        int Lsum = (root->left) ? root->left->data : 0;
    
        int Rsum = (root->right) ? root->right->data : 0;
        
        if(root->left || root->right){
            if(Lsum + Rsum != root->data)
                return false;}
         
     bool leftProperty = isSumProperty(root->left);
     bool rightProperty = isSumProperty(root->right);

     
     return leftProperty && rightProperty;
     
    }
};
