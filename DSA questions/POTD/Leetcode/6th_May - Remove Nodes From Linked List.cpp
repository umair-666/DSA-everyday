// 2487. Remove Nodes From Linked List
// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        if(head==NULL)return head;
        head->next = removeNodes(head->next);
        if(head->next==NULL)return head;
        if(head->next->val>head->val)return head->next;
        return head;
    }
};
