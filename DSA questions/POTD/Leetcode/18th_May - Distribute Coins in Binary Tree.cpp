// 979. Distribute Coins in Binary Tree
// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18

class Solution {
private:
    int dis(TreeNode* root, int& ans) {
        if( !root ) return 0;
        int coins = root->val + dis(root->left, ans) + dis(root->right, ans);
        coins--;
        ans += abs(coins);
        return coins;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        dis(root, ans);
        return ans;
    }
};
