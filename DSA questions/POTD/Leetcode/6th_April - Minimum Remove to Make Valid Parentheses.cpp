// 1249. Minimum Remove to Make Valid Parentheses
// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/?envType=daily-question&envId=2024-04-06


class Solution {
public:
    string minRemoveToMakeValid(std::string s) {
        int l = 0;
        int r = 0;
        stack<char> stack;

        // Pass 1
        for (char ch : s) {
            if (ch == '(')
                l++;
            else if (ch == ')')
                r++;
            if (r > l){
                r--;
                continue;
            } else 
                stack.push(ch);
        }

        string res = "";
        
        // Pass 2
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (l > r && currentChar == '(')
                l--;
            else 
                res += currentChar;
        }

        // Reverse the result string
        reverse(res.begin(), res.end());
        return res;
    }
};
