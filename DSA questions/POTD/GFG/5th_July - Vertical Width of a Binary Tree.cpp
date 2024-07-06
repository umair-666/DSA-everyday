// Vertical Width of a Binary Tree
// https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

//Back-end complete function Template for C++
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
       if(!root) return 0;
        map<int, map<int, multiset<int>>>mp;
        queue<pair<Node* , pair<int, int>>>q;
        q.push({root , {0 , 0}});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *ptr = q.front().first;
                int axis = q.front().second.first;
                int level = q.front().second.second;
                q.pop();
                mp[axis][level].insert(ptr->data);
                if(ptr->left){
                    q.push({ptr->left , {axis-1 , level+1}});
                }
                
                if(ptr->right){
                    q.push({ptr->right , {axis+1 , level+1}});
                }
            }
        }
        
        return mp.size();
    }
};
