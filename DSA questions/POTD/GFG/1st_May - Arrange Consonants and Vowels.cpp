// Arrange Consonants and Vowels
// https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1


class Solution {
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
  public:
    struct Node* arrangeCV(Node* head) {
        Node *dummy = new Node(1);
        dummy->next = head;
        
        Node *vowel = dummy;
        
        // Move the vowels pointer to the last vowel from the start
        while (vowel->next and isVowel(vowel->next->data)) {
            vowel = vowel->next;
        }
        
        // If the linked list had only vowels
        if (!vowel->next)
            return dummy->next;
        
        
        Node *tmp = vowel->next->next;
        Node *prev = vowel->next;
        
        while (tmp) {
            
            // If it's a vowel, then it needs to come after the 'vowel' ptr
            if (isVowel(tmp->data)) {
                prev->next = tmp->next;
                tmp->next = vowel->next;
                
                vowel->next = tmp;
                vowel = vowel->next;
            }
            
            prev = tmp;
            tmp = tmp->next;
        }
        
        return dummy->next;
    }
};
