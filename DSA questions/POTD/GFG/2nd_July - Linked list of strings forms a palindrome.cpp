// Linked list of strings forms a palindrome
// https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1


class Solution {
    bool isPalindrome(string str){
        int s=0, e = str.size()-1;
        while(s < e){
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }
  public:
    bool compute(Node* head) {
        Node* temp = head;
        string str = "";
        while(temp){
            str +=temp->data;
            temp = temp->next;
        }
        
        return isPalindrome(str);
    }
};
