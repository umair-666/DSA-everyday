// 633. Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            if (c % i == 0) {
                int exponentCount = 0;
                while (c % i == 0) {
                    exponentCount++;
                    c /= i;
                }
                if (i % 4 == 3 && exponentCount % 2 != 0) {
                    return false;
                }
            }
        }
        return c % 4 != 3;
    }
};
