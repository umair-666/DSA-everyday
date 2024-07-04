// 2181. Merge Nodes in Between Zeros
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Start with the first non-zero value.
        head = head->next;
        if (!head)
            return head;

        ListNode* temp = head;
        int sum = 0;
        while (temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }

        head->val = sum;
        head->next = mergeNodes(temp);
        return head;
    }
};
