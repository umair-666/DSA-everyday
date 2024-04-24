// 1137. N-th Tribonacci Number
// https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;

        int a = 0, b = 1, c = 1,d;
        for(int i=3;i<=n;i++){
            d = a+b+c;
            a = b, b = c, c = d;
        }
        return c;
    }
};
