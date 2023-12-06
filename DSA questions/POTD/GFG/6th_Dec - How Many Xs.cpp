// How Many X's?
// https://www.geeksforgeeks.org/problems/how-many-xs4514/1
 
class Solution {
  public:
    int countX(int L, int R, int X) {
        // code here
        int cnt = 0;
        
        for(int i=L+1;i<R;i++){
            int num = i;
            while(num){
                if(num%10 == X)
                     cnt++;
                num /=10;
            }
        }
        
        return cnt;
    }
};
