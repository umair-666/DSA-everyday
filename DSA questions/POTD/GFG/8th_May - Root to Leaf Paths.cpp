// Root to Leaf Paths
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1


class Solution {    
void solve(Node* root, vector<int>v, vector<vector<int>>&ans){
     if(root == NULL)    return ;
     v.push_back(root->data) ;
     if( root->left == NULL && root->right == NULL ){
         ans.push_back(v) ;
     }
     solve(root->left, v, ans) ;
     solve(root->right, v, ans) ;
     v.pop_back() ;
}
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans ;
     solve(root, {}, ans) ;
     return ans ;
    }
};
