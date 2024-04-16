// 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
    void dfs(TreeNode* root, int val, int depth, int level){
        if (!root) return;
        
        if (level < depth-1){
            dfs(root->left, val, depth, level+1);
            dfs(root->right, val, depth, level+1);
        }
        else{
            TreeNode* ptr=root->left;
            root->left=new TreeNode(val);
            root->left->left=ptr;

            ptr=root->right;
            root->right=new TreeNode(val);
            root->right->right=ptr;
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* ptr = new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        dfs(root, val, depth, 1);
        return root;
    }
};
