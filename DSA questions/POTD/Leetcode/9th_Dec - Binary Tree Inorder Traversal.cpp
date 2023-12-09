// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=daily-question&envId=2023-12-09

Recursive:

class Solution {
     void inorder(TreeNode* root , vector<int> &ans){

        if(root == NULL)
            return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
         //LNR
        vector<int> ans;
        inorder(root,ans);
        
        return ans;
    }
};

Morris Traversal:

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{                       //go to righmost guy of leftsubtree
                TreeNode* prev = cur->left;
                while(prev->right && prev->right!=cur)
                    prev = prev->right;
                
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{      // prev is already pointing to root
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};
