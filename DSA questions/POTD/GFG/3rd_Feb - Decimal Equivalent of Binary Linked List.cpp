// Decimal Equivalent of Binary Linked List
// https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1

#include <bitset>
#include <string>
class Solution {
public:
    long long unsigned int decimalValue(Node *head) {
    
    int MOD = 1000000007; // Define the modulo value
        
        if (!head) return 0;

        long long unsigned int result = 0; 

        while (head) {
            int n = head->data;
            result = (result * 2 + n) % MOD; 
            head = head->next;
        }

        return result;
    }
};


