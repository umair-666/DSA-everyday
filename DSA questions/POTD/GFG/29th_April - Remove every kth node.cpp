// Remove every kth node
// https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

/* Link list Node 

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

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(!head or K==1){
            return NULL;
        }
      
      Node *temp1 = head;
      Node *temp2 = head;
      int p = K-1;
      int k = K-1;
      while(temp1){
          if(k > 0){
              temp2=temp1;
              k--;
          }
          else{
              k = p;
              temp2->next = temp1->next;
          }
          temp1 = temp1->next;
      }
      return head;
    }
};
