// Reverse Level Order Traversal
// https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
           int levelSize = q.size();
           for(int i=0;i<levelSize;i++){
               Node* node = q.front();
               q.pop();
               ans.push_back(node->data);
               
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
           }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
