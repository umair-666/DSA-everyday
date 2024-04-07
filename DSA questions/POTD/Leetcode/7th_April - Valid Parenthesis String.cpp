// 678. Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07

class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.size() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
};
