// Minimum steps to destination
// https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1

class Solution {
  public:
    int minSteps(int d) {
        // code here
        int sum=0,steps=0,i=0;
        while(sum<d){
            sum+=steps;
            steps++;
        }
        while((sum-d)%2==1){
            sum+=steps;
            steps++;
        }
      return steps-1;
    }
};
