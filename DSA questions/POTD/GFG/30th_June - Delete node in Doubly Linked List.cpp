// Delete node in Doubly Linked List
// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1


class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
        if(!head_ref)
            return NULL;
        
       if (x == 1) {
        head_ref = head_ref->next;
        if (head_ref)
            head_ref->prev = NULL;  // Update the previous pointer of the new head
        return head_ref;
    }
        Node* pre = NULL;
        Node* curr = head_ref;
        
        int c =1;
        while(curr && c != x){
            pre = curr;
            curr = curr->next;
            c++;
        }
        
        if (!curr) 
            return head_ref; // Position x is out of bounds
            
        pre->next = curr->next;
        if (curr->next)
            curr->next->prev = pre;
            
        delete curr;
        return head_ref;
    }
};
