// 201. Bitwise AND of Numbers Range
//  https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

// Approach - 1
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while (left != right) {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        return (left << cnt);
    }
};

// Approach -2
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left){
            right&=(right-1);
        }
        return right;
    }
};
