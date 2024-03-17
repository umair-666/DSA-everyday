// Count Pairs whose sum is equal to X
// https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
       if(!head1 || !head2) return 0;
       
       int cnt = 0;
       
       unordered_set<int> s2;
        while (head2) {
            s2.insert(head2->data);
            head2 = head2->next;
        }
        
        while (head1) {
            int num = x - head1->data;
            if(s2.find(num) != s2.end())
                cnt++;
            head1 = head1->next;
        }
        return cnt;

    }
};
