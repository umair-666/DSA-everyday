// 1038. Binary Search Tree to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25

class Solution {
    // Perform any traversal of your choice to store node values.
    void inorder(TreeNode* root, vector<int>& inorderTraversal) {
        if (!root) {
            return;
        }
        inorder(root->left, inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right, inorderTraversal);
    }
    // Function to modify the values in the tree.
    void replaceValues(TreeNode* root, vector<int>& inorderTraversal) {
        if (!root) {
            return;
        }
        replaceValues(root->left, inorderTraversal);
        replaceValues(root->right, inorderTraversal);

        int nodeSum = 0;
        // Replace node with values greater than the current value.
        for (auto i : inorderTraversal) {
            if (i > root->val) {
                nodeSum += i;
            } else {
                break;
            }
        }

        root->val += nodeSum;
    }

    public:
    TreeNode* bstToGst(TreeNode* root) {
        // Store the inorder traversal in an array.
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);

        // Reverse the array to get descending order.
        reverse(inorderTraversal.begin(), inorderTraversal.end());

        // Modify the values in the tree.
        replaceValues(root, inorderTraversal);

        return root;
    }
};
