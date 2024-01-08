// Merge 2 sorted linked list in reverse order
// https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1

class Solution{
    public:
    Node* reverseNodes(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node* NewNode = newNode(-1);
        Node* tail = NewNode;

        while (true) {
            if (node1 == NULL) {
                tail->next = node2;
                break;
            }
            if (node2 == NULL) {
                tail->next = node1;
                break;
            }
            if (node1->data < node2->data) {
                tail->next = node1;
                node1 = node1->next;
            }
            else {
                tail->next = node2;
                node2 = node2->next;
            }
            tail = tail->next;
        }

        // reverse 
        return reverseNodes(NewNode->next);
    }
};

       
