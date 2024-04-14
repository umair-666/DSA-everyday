// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)   return 0;

        int sum = 0;
        if(root->left && !root->left->left && !root->left->right)
            sum += root->left->val;
        sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        return sum;
    }
};
