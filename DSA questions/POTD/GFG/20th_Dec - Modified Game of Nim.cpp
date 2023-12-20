// Modified Game of Nim
// https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1

class Solution{
public:
    int findWinner(int n, int A[]){
        int xo = 0;
        for(int i=0;i<n;++i)
            xo ^= A[i];
        
        if(!xo) return 1;
        else    return (n%2)+1;
    }
};
