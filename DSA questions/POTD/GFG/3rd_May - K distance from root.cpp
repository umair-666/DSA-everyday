// K distance from root
// https://www.geeksforgeeks.org/problems/k-distance-from-root/1

class Solution{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
          vector<int> ans;
          queue<Node*> q;
          q.push(root);
          q.push(NULL);
          int level = 0;
          
          while(! q.empty()) {
              
              Node* node = q.front();
              q.pop();
              
              if(node == NULL ) {
                  
                  if(!q.empty()) q.push(NULL);
                  
                  level++;
                  if(level == k+1) break;
              }
              
              else {
                  if(level == k) {
                      ans.push_back(node->data);
                  }
                  
                  if(node->left) q.push(node->left);
                  if(node->right) q.push(node->right);
              }
          }
          
          return ans;
    }
};
