// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/description/?envType=daily-question&envId=2024-03-07

// Noob approach:

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        int mid = cnt/2;

        ListNode* node = head;
        while(mid--){
            node = node->next;
        }

        return node;
    }
};

// Pro approach:

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(!head)   return head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast->next)
                fast = fast->next;
        }
        return slow;


    }
};
