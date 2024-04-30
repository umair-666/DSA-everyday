// Add two numbers represented by linked lists
// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution{
      //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        if(!head || !head->next){
            return head;
        }
        struct Node* temp = reverse(head->next);
        head->next->next=head;
        head->next = NULL;
        return temp;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        struct Node* temp = num1;
        struct Node* temp1 = num2;
        while(temp && temp->data==0){
            temp=temp->next;
        }
        temp = reverse(temp);
        while(temp1 && temp1->data==0){
            temp1=temp1->next;
        }
        temp1 = reverse(temp1);
        int carry = 0;
        struct Node* h1 = temp;
        struct Node* h2 = temp1;
        struct Node* dummy = new Node(0);
        struct Node* h3 = dummy;
        while(h1!=NULL && h2!=NULL){
            int sum = h1->data+h2->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        while(h1!=NULL){
            int sum = h1->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h1 = h1->next;
        }
        while(h2!=NULL){
            int sum = h2->data+carry;
            carry = sum/10;
            sum = sum%10;
            h3->next = new Node(sum);
            h3 = h3->next;
            h2 = h2->next;
        }
        while(carry){
            h3->next = new Node(carry);
            carry = 0;
        }
        if(!dummy->next){
            return dummy;
        }
        return reverse(dummy->next);
    }
};
