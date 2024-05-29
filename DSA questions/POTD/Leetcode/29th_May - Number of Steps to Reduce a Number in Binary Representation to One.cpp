// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29

class Solution {
public:
    int numSteps(string s) {
        int res = 0, carry = 0;
    for (auto i = s.size() - 1; i > 0; --i) {
        ++res;
        if (s[i] - '0' + carry == 1) {
            carry = 1;
            ++res;
        }
    }
    return res + carry;
    }
};
