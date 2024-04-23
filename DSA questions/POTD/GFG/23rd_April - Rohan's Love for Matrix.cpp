// Rohan's Love for Matrix
// https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1

class Solution {
  public:
    int firstElement(int n) {
        int MOD = 1e9+7;
        long long a=1,b=0;
        
        for(int i=0;i<n-1;i++){
            long long st = a;
            a = (a+b)%MOD;
            b = st;
        }
        
        return a;
    }
};
