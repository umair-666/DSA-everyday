// Serialize and deserialize a binary tree
// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Solution{
    void preorder(vector<int>&ans,Node *root){
        if(root==NULL)  return;
        
        preorder(ans,root->left);
        ans.push_back(root->data);
        preorder(ans,root->right);
    }
    
public:
    vector<int> serialize(Node *root) {
        vector<int>ans;
        preorder(ans,root);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        return ans;
    }
    
    Node * deSerialize(vector<int> &A){
       return NULL;
    }

};
