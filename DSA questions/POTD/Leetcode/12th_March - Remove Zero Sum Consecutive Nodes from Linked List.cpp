// 1171. Remove Zero Sum Consecutive Nodes from Linked List
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/?envType=daily-question&envId=2024-03-12

 class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix_sum = 0;
        std::unordered_map<int, ListNode*> prefix_sums;
        prefix_sums[0] = dummy;
        ListNode* current = head;

        while (current) {
            prefix_sum += current->val;
            if (prefix_sums.find(prefix_sum) != prefix_sums.end()) {
                ListNode* to_delete = prefix_sums[prefix_sum]->next;
                int temp_sum = prefix_sum + to_delete->val;
                while (to_delete != current) {
                    prefix_sums.erase(temp_sum);
                    to_delete = to_delete->next;
                    temp_sum += to_delete->val;
                }
                prefix_sums[prefix_sum]->next = current->next;
            } else {
                prefix_sums[prefix_sum] = current;
            }
            current = current->next;
        }

        return dummy->next;
    }
};
