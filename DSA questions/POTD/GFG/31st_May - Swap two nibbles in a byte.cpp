// Swap two nibbles in a byte
// https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

class Solution {
  public:
    int swapNibbles(int n) {
        int num=0;
    for(int i=0;i<8;i++){
        //first check which bit is set
        if(n& 1<<i){
            //if it is set then find its new position in num
            int position=(4+i)%8;
            //now set this position in num
            num=num | (1<<position);
        }
    }
    return num;   
    
    }
};
