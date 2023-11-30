// Shortest path from 1 to n
// https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

class Solution{   
public:
   int minimumStep(int n){
        int count=0;
        while(n!=1) {
            if(n%3==0){
                n = n/3;
            }
            else {
                n--;
            }
            count++;
        }
        return count;
    }
};
