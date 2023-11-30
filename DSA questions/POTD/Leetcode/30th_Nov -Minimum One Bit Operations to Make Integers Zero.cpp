// 1611. Minimum One Bit Operations to Make Integers Zero
// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/?envType=daily-question&envId=2023-11-30

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res;
        for (res = 0; n > 0; n &= n - 1)
            res = -(res + (n ^ (n - 1)));
        return abs(res);
    }
};
