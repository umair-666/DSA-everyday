// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

class Solution {

    int helper(TreeNode* root , int sum){
        if(root == NULL)
            return 0;
        
        sum= sum * 10 + root->val;

        //leaf nodes
        if( !root->left && !root->right) //check for leaf nodes
            return sum;
        
        return helper(root->left,sum) + helper(root->right,sum);  
    }
public:
    int sumNumbers(TreeNode* root) {
        
        if(root == NULL)
            return 0;

        return helper(root,0); //sum = 0 initially
    }
};
