// 19.  Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i < n + 1; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;
        delete toRemove;

        return dummy->next;
    }
};

