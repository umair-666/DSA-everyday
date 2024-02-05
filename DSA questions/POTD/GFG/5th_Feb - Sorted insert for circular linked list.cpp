// Sorted insert for circular linked list
// https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */
 
// This function should return head of
// the modified list
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        Node *newNode = new Node(data);
       Node *temp = head;
       
       //if n=0, return new node
       if (!head){
           newNode -> next = newNode;
           return newNode;
       }
       
       //if newNode = first node!
       else if (data <= head->data){
            newNode -> next = head;
            while (temp -> next != head)
                temp = temp->next;
           
           temp -> next = newNode;
           return newNode;
       }
            
       //if n>=2, check for 2 adjacent nodes & insert accordingly
        else{
            while (temp->next != head && data > temp->next->data){
                temp = temp->next;
            }
            
            newNode -> next = temp->next;
            temp -> next = newNode;
            return head;
        }       
    }
};
