// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21

// Inplace Reversal of LL:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)    
            return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw;
        while(curr){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
};
