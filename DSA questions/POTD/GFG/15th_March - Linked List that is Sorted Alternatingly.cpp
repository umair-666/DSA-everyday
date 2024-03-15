// Linked List that is Sorted Alternatingly
// https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

class Solution{
    public:
    void sort(Node **head){
        Node *curr = *head;
        Node* temp= curr;
        vector<int> v;
        while(temp){
            v.push_back(temp->data);   
            temp = temp->next;
        }
        std::sort(v.begin(), v.end());
        
        for(auto it : v){
            curr->data = it;
            curr = curr->next;
        } 
    }
};

// TC = O(n) SC = O(1)
class Solution {
public:
//  to achieve O(n) time complexity and O(1) space complexity, you can use counting sort, which is a non-comparison based sorting algorithm.
    void sort(Node **head) {
        // Find the maximum value in the linked list
        Node *curr = *head;
        int maxVal = INT_MIN;
        while (curr) {
            maxVal = max(maxVal, curr->data);
            curr = curr->next;
        }
        
        // Initialize count array with 0s
        vector<int> count(maxVal + 1, 0);
        
        // Count occurrences of each value in the linked list
        curr = *head;
        while (curr) {
            count[curr->data]++;
            curr = curr->next;
        }
        
        // Overwrite the original linked list with sorted values
        curr = *head;
        int idx = 0;
        for (int i = 0; i <= maxVal; ++i) {
            while (count[i]--) {
                curr->data = i;
                curr = curr->next;
            }
        }
    }
};
  
