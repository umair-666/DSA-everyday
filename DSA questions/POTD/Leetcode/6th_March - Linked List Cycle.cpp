// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/?envType=daily-question&envId=2024-03-06

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)     return false;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)    return true;
        }
        return false;
    }
};
