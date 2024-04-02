// Minimum Absolute Difference In BST
// https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

// TC : O(N), SC: O(N) ->
class Solution{
    void inorder(Node* root, vector<int> &v){
        if(!root)   return;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    public:
    int absolute_diff(Node *root){
        vector<int> v;
        inorder(root, v);
        
        int mini = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            int diff = abs(v[i] - v[i - 1]);
            mini = min(mini, diff);
        }
        return mini;
    }
};

// TC : O(N), SC: O(1) ->
class Solution{
   void inorder(Node* root,int &ans,int &k){
        if(!root)   return;
        
        inorder(root->left,ans,k);
        ans=min(ans,abs(k-root->data));
        k=root->data;
        inorder(root->right,ans,k);
    }
    public:
    int absolute_diff(Node *root){
        int ans=1e9,k=-1e9;
        inorder(root,ans,k);
        return ans;
    }
};
