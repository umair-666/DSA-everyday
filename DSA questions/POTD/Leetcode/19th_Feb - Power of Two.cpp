// 231. Power of Two
// https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<=0)    return false;
        // double logValue = log2(n);
        // return ceil(logValue) == floor(logValue);
        
        //OR
        
        return n > 0 && not (n & n - 1);

    }
};
