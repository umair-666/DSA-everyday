//Paths from root with a specified sum
//https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution{
    
     void helper(Node *root, int sum, vector<int> &currentPath, vector<vector<int>> &ans){
        if(!root)   return;
        
        currentPath.push_back(root->key);
        
        int rem_sum = sum - root->key;
        
        if(rem_sum == 0){
            ans.push_back(currentPath);
        }
        
        vector<int> leftPath = currentPath;
        vector<int> rightPath = currentPath;
        
        helper(root->left,rem_sum, leftPath,  ans);
        helper(root->right, rem_sum,rightPath, ans);
        
    }
    public:
    vector<vector<int>> printPaths(Node *root, int sum){
        
        vector<vector<int>> ans;
        
        vector<int> currentPath;
        
        helper(root,sum,currentPath,ans);
        return ans;
    }
};
