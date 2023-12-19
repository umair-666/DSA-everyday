// Rightmost different bit
// https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
         // Find XOR of M and N
        int xorResult = m ^ n;

        // If M and N are the same, return -1
        if (xorResult == 0) {
            return -1;
        }

        // Find the position of the rightmost set bit in xorResult
        int position = 1;
        while ((xorResult & 1) == 0) {
            xorResult >>= 1;
            position++;
        }
      
    return position;
    }
};
