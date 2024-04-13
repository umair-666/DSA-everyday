// Reverse Bits
// https://www.geeksforgeeks.org/problems/reverse-bits3556/1

class Solution {
  public:
    long long reversedBits(long long x) {
       long long res = 0;
       for(int i=0;i<32;i++){
            if(((1<<i)&x)!=0){
                    res+=((1L<<31-i));
            }
        }
        return res;
    }
};
