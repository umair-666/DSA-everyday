// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root)   return -1;

        queue<TreeNode*> q;
        q.push(root);
        int leftmostVal = -1;

        while(!q.empty()){
            int levelsize = q.size();
            leftmostVal = q.front()->val;
            for(int i = 0;i<levelsize;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right)  q.push(node->right);
            }
        }

        return leftmostVal;
    }
};
