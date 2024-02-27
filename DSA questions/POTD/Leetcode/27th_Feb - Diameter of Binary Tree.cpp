// 543. iameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

class Solution {
    int fun(TreeNode* root, int &dia){
        if(!root)   return 0;

        int lt =  fun(root->left,dia);
        int rt =  fun(root->right,dia);
        
        dia = max(dia, lt+rt);

        return 1 + max(lt,rt);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        fun(root,dia);
        return dia;
    }
};
