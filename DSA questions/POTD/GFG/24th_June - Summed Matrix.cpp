// Summed Matrix
// https://www.geeksforgeeks.org/problems/summed-matrix5834/1

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
       long long res = n - abs(n - (q-1));
        return res >= 0? res: 0;
    }
};
