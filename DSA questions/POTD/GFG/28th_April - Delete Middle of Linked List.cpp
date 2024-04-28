// Delete Middle of Linked List
// https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
         Node *fast=head,*slow=head,*pre=head;
        while(fast && fast->next){
            fast=fast->next->next;
            pre=slow;
            slow=slow->next;
        }
        pre->next=slow->next;
        return head;
    }
};
