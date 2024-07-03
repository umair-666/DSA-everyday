// Remove all occurences of duplicates in a linked list
// https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1


class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        
        Node* temp = head;       
        Node* prev = NULL;     
      
        while (temp && temp->next) {          
            if (temp->data != temp->next->data) {                     
                prev = temp;                                                           
                temp = temp->next;                                               
                continue;
            }
    
            while (temp->next && temp->data == temp->next->data) {     
    
                Node* toDel = temp->next;                                                                    
    
                temp->next = temp->next->next;                                                          
                delete toDel;                                                                                             
            }
            
            Node* toDel = temp;                  
            if (temp == head)                   
                head = temp->next;
            else 
                prev->next = temp->next;    

            temp = temp->next;                  
            delete toDel;                               
        }
    
        return head;
    }
};
