// 143. Reorder List
// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* mid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward;

        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode* midNode = mid(head);
        ListNode* hf = head;
        ListNode* hs = reverseList(midNode);

        // Merge
        while (hf && hs) {
            ListNode* temp = hf->next;
            hf->next = hs;
            hf = temp;

            temp = hs->next;
            hs->next = hf;
            hs = temp;
        }

        if (hf)
            hf->next = nullptr;
    }
};
