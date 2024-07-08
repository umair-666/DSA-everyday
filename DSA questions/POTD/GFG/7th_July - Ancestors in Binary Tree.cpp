// Ancestors in Binary Tree
// https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

// User function template for C++

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
    bool solve(Node*root,int target,vector<int>&ans){
    if(root==NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    bool Validate = solve(root->left,target,ans) || solve(root->right,target,ans);
    if(Validate){
        ans.push_back(root->data);
    }
    else{
        return false;
    }
}
    
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
         vector<int>ans;
        solve(root,target,ans);
        return ans;
    }
};
