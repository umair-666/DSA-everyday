// 1190. Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                // Store the current length as the start index for future
                // reversal
                openParenthesesIndices.push(result.length());
            } else if (currentChar == ')') {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                // Reverse the substring between the matching parentheses
                reverse(result.begin() + start, result.end());
            } else {
                // Append non-parenthesis characters to the processed string
                result += currentChar;
            }
        }
        return result;
    }
};
