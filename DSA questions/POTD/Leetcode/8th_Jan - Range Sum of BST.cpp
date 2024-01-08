// 938.Range Sum of BST
// https://leetcode.com/problems/range-sum-of-bst/description/?envType=daily-question&envId=2024-01-08

// Approach 1 : TC = O(N) SC = O(N)
class Solution {

    void inorder(TreeNode* root , vector<int> &ans){
        if(!root)   return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;

        inorder(root,ans);

        int l = 0, h = 0, sum = 0;
        for(int i=0;i<ans.size();i++){
           if(ans[i] == low)
            l = i;
            if(ans[i] == high)
                h = i;
        }

        for(int i=l;i<=h;i++){
            sum +=ans[i];
        }

        return sum;
    }
};

// Approach 2 : TC = O(N) SC = O(N)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        
        int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;
        
        int leftSum = rangeSumBST(root->left, low, high);
        int rightSum = rangeSumBST(root->right, low, high);
        
        return currentVal + leftSum + rightSum;
    }
};
