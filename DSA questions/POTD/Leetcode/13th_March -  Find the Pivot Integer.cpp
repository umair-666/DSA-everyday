// 2485.  Find the Pivot Integer
// https://leetcode.com/problems/find-the-pivot-integer/description/?envType=daily-question&envId=2024-03-13

class Solution {
public:
    int pivotInteger(int n) {
        int l = 0, r = 0;
        r = n * (n + 1) / 2;
        
        for(int i=1;i<=n;i++){
            l +=i;
            if(l==r)
                return i;
            r -=i;
        }
    return -1;
    }
};
