// 1903. Largest Odd Number in String
// https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=daily-question&envId=2023-12-07

class Solution {
public:
    string largestOddNumber(string num) {
        
        while(!num.empty() && (int)num.back() % 2 == 0)
            num.pop_back();
        
        return num;
    }
};
