// Insertion Sort for Singly Linked List
// https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref){
        
        if(head_ref==NULL || head_ref->next==NULL) return head_ref;
        Node* d=new Node(-1);
        d->next=head_ref;
        Node* node=head_ref->next, *prev=head_ref;
        while(node){
            if(node->data>=prev->data){
                prev=node;
                node=node->next;
                continue;
            }
            Node* temp=d;
            while(node->data>temp->next->data){
                temp=temp->next;
            }
            prev->next=node->next;
            node->next=temp->next;
            temp->next=node;
            node=prev->next;
        }
        return d->next;
    }  
};
