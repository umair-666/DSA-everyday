// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/?envType=daily-question&envId=2024-03-22

// Approach 1 - 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* temp = head;
        while(temp){
            res.push_back(temp->val);
            temp = temp->next;
        }

        int s = 0, e = res.size()-1;
        while(s<e){
            if(res[s++] != res[e--])
                return false;
        }
        return true;
    }
};

// Approach 2 - 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // Empty or single-node list is a palindrome
        
        // Find the middle of the linked list using two pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        slow->next = NULL; // Break the original list
        
        // Compare the first half with the reversed second half
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1 && p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
