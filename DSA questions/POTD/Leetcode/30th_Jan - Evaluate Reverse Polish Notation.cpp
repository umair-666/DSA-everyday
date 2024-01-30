// 150.Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution {

    int performOperation(int num1, int num2, char op) {
        if (op == '+') return num1 + num2;
        if (op == '-') return num1 - num2;
        if (op == '*') return num1 * num2;
        if (op == '/') return num1 / num2;
        return 0;  // Handle unsupported operator
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {  // Check if an operator
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();
                s.push(performOperation(num1, num2, token[0]));
            } else {  // If a number, push to stack
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
