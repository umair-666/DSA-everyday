// Make Binary Tree From Linked List
// https://www.geeksforgeeks.org/problems/make-binary-tree/1

class Solution {
  public:
    void convert(Node *head, TreeNode *&root) {
        if(!head){
            root = NULL;
            return;
        }
        
        queue<TreeNode*>q;
        
        root=new TreeNode(head->data);
        q.push(root);
        
        head=head->next;
        
        while(head){
            TreeNode* par=q.front();
            q.pop();
            
            TreeNode *left=NULL, *right=NULL;
            
            left=new TreeNode(head->data);
            head=head->next;
            q.push(left);
            if(head){
                right=new TreeNode(head->data);
                head=head->next;
                q.push(right);
            }
            par->left=left;
            par->right=right;
        }
        return;
    }
};
