// Minimum element in BST
// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

// TC : O(N) SC :O(N)
class Solution {
    void inorder(Node* root,vector<int> &v){
        if(!root)   return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
  public:
    int minValue(Node* root) {
        vector<int> v;
        inorder(root,v);
        return v[0];
    }
};

// TC : O(height of BST) , SC: O(1)

int minValue(Node* root) {
    // Code here
    if(!root)   return -1;
    if(!root->left) return root->data;
    
    minValue(root->left);
}
