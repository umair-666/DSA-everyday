// Merge Sort on Doubly Linked List
// https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
       vector<int> v;
        Node *temp = head;
        while(temp != NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        
        sort(v.begin(), v.end());
        temp = head;
        int i=0;
        while(i < v.size()){
            temp->data = v[i++];
            temp = temp->next;
        }
        return head;
    }
};
