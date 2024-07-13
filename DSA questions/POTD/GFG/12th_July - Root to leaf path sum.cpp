// Root to leaf path sum
// https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

class Solution {
      bool dfs(Node*r,int t,int& s){
        if(r==NULL){
            return false;
        }
        s+=r->data;
        
        if(dfs(r->left,t,s)==false and
        dfs(r->right,t,s)==false){
            if(s==t and (r->left==NULL and r->right==NULL)) {
                
                return true;
            }
            else
            s-=r->data;
           
        }
        else return true;
       
        return false;
        
    }
  public:
    bool hasPathSum(Node *root, int target) {
         int s=0;
        return dfs(root,target,s);
    }
};
