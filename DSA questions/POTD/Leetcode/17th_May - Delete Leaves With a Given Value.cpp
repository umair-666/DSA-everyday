// 1325. Delete Leaves With a Given Value
// https://leetcode.com/problems/delete-leaves-with-a-given-value/description/?envType=daily-question&envId=2024-05-17

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        if(!root)   return root;

        root->left = removeLeafNodes(root->left, target); 

        root->right = removeLeafNodes(root->right, target); 
 
        if ( !root->left && !root->right && root->val == target)
            return nullptr;
        
        return root;
    }
};
