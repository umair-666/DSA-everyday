// 872.Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

// TC = O(N) SC = O(N)

class Solution {
    void bfs(TreeNode* root, vector<int>& leafValues) {
        if (!root) return;
        if (!root->left && !root->right)
            leafValues.push_back(root->val);

        bfs(root->left, leafValues);
        bfs(root->right, leafValues);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return false;

        vector<int> leafValues1, leafValues2;

        bfs(root1, leafValues1);
        bfs(root2, leafValues2);

        // Early exit if the sizes are different
        if (leafValues1.size() != leafValues2.size())
            return false;

        // Comparison loop with increment statement
        for (int i = 0; i < leafValues1.size(); ++i) {
            if (leafValues1[i] != leafValues2[i])
                return false;
        }

        return true;
    }
};
