// Check whether BST contains Dead End
// https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

  class Solution{
    bool isDead(Node* root, int min, int max)
    {
        if (!root)  return false;
        
        int val = root->data;
        
        if ( !root->left && !root->right)
        {
            if (val == min + 1 && val == max - 1)
                return true;
            else
                return false;
        }
        
        bool ret1 = isDead(root->left, min, val);
        bool ret2 = isDead(root->right, val, max);
        
        return ret1 || ret2;
      
    }
  public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return isDead(root,0,10005);
    }
};

