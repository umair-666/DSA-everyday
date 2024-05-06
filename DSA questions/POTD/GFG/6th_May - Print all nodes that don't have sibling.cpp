// Print all nodes that don't have sibling
// https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

Node* solve(Node* root,vector<int>&ans){
    if(!root)return root;
    
    Node* left=solve(root->left,ans);
    Node* right=solve(root->right,ans);
    
    if(left && !right)
        ans.push_back(left->data);
        
    if(right && !left)
        ans.push_back(right->data);
        
    return root;
}
vector<int> noSibling(Node* node){
    vector<int>ans;
    Node* root = solve(node,ans);
    sort(ans.begin(),ans.end());
    
    if(ans.size() == 0)
        return {-1};
        
    return ans;
}
