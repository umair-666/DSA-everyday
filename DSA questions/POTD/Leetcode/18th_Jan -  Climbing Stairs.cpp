// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
// Question is fibonacci series in dsiguise

// Approach 1: gives TLE
class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0 ||n==1)
            return 1;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// Approach 2: Most efficient
class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1;

        for(int i=1;i<=n;i++){
            int c = a + b;
            a = b;
            b =c;
        }
        return b;
    }
};
