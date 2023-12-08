// 606. Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2023-12-08

class Solution {
    void preorder(TreeNode* root, string &s){
        if(!root)   return;

        s += to_string(root->val);

        if(root->left || root->right){
            s.push_back('(');
            preorder(root->left ,s);
            s.push_back( ')' );
        }
        if(root->right){
            s.push_back('(');
            preorder(root->right,s);
            s.push_back( ')');
        }
        
    }
public:
    string tree2str(TreeNode* root) {
        string s = "";
        preorder(root,s);
        return s;
    }
};
// Omit the empty parenthesis pairs if the right node of root is null, that do not affect binary tree representation.
// if the left node is null and right node have a value include the empty parenthesis of left node, if you omit the left node it affect the binary tree representation.
