// Level order traversal
// https://www.geeksforgeeks.org/problems/level-order-traversal/1

class Solution{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(!root)   return ans;

        queue<Node*> q;
        q.push(root);  
        
        while(!q.empty()){
            int size = q.size(); //level size
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->left)    q.push(node->left);
                if(node->right)    q.push(node->right);
                ans.push_back(node->data);
            }
        }

        return ans;
        
       // TC O(n).   SC O(N)
    }
};
