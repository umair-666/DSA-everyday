// Kth common ancestor in BST
// https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1

class Solution{
     int fun(Node * root,int x,int y ,int &k){
        if(root==NULL){
            return -1;
        }
        int val=-1;
        if((root->data > x  )&& (root->data)> y){
            val=fun(root->left,x,y,k);
        }
        else if((root->data < x  )&& (root->data< y)){
            val=fun(root->right,x,y,k);
        }
        k--;
        if(k==0){
            val=root->data;
        }
        return val;
    }
    public:
    
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y){
        
         return fun(root,x,y,k);
    }
};
