// Closest Neighbour in BST
// https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

class Solution {
    void inorder(Node* root, vector<int> &v){
        if(!root)   return;
        
        inorder(root->left, v);
        v.push_back(root->key);
        inorder(root->right,v);
    }
  public:
    int findMaxForN(Node* root, int n) {
        if(!root)   return -1;
        vector<int> v;
        inorder(root,v);
        
        for(int i = v.size()-1;i>=0;i--){
            if(v[i] <= n)
                return v[i];
        }
        
        return -1;
    }
};
