// 2816. Double a Number Represented as a Linked List
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/?envType=daily-question&envId=2024-05-07

class Solution {
    int twiceOfVal(ListNode* head){
        if (!head) return 0;

        int doubledValue = head->val * 2 + twiceOfVal(head->next);
        
        head->val = doubledValue % 10;
        
        return doubledValue / 10;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = twiceOfVal(head);
        
        // If there's a carry, insert a new node at the beginning with the carry value
        if (carry) 
            head = new ListNode(carry, head);
        
        return head;
    }
};
