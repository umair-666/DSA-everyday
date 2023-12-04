// 2264. Largest 3-Same-Digit Number in String
// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04

class Solution {
public:
    string largestGoodInteger(string num) {

        int good = -1;

        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i+1] == num[i + 2]) {
                good = max(good , num[i] - '0');
            }
        }

        if (good == -1) return "";
    
        return string(3, good + '0');
    }
};

// std::string: This is the C++ standard library class for handling strings.

// (3, '0' + result): This creates a string with a length of 3 characters,
and each character is determined by adding the ASCII value of '0' to the value of result.
