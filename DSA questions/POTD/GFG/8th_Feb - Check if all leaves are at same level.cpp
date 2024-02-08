// Check if all leaves are at same level
// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    int leafDepth = -1; 
    
    int helper(Node* root, int depth){
        if(!root) return true; 
        
        // Check if it's a leaf node
        if (!root->left && !root->right) {
            // If it's the first leaf node encountered, set the leafDepth
            if (leafDepth == -1) {
                leafDepth = depth;
            } else {
                // If it's not the first leaf node encountered, compare its depth with leafDepth
                if (depth != leafDepth) return false;
            }
        }
        
        // Recursively check left and right subtrees
        return helper(root->left, depth + 1) && helper(root->right, depth + 1);
    }
    
  public:
    bool check(Node *root) {
    
        if (!root) return true;
        
        return helper(root, 0);
    }
};
