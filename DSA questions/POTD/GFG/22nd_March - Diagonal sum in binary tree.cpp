// Diagonal sum in binary tree
// https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

class Solution {
    void helper(Node* root, vector<int> &res, int p) {
        if(!root)   return;
        
        if(res.size() == p)
            res.push_back(root->data);
        else
            res[p] += root->data;
            
        helper(root->right, res, p);
        helper(root->left, res, p+1);
    }
  public:
    vector<int> diagonalSum(Node* root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
};
