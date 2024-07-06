// Populate Inorder Successor for all nodes
// https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1


class Solution {
     void populate(Node*root,Node*&prev)
    {
        if(root==NULL)
        {
            return;
        }
        populate(root->left,prev);
        if(prev==NULL)
        {
            prev=root;
        }
        else{
            prev->next=root;
            prev=root;
            
        }
        populate(root->right,prev);
        
    }
  public:

    void populateNext(Node *root) {
        Node*prev=NULL;
        populate(root,prev);
    }
};
