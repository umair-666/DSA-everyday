// Number of Rectangles in a Circle
// https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int ans = 0;
        for(int i=1;i<2*r;i++){
            int maxi = sqrt(2*r*2*r - i*i);
            ans+=maxi;
        }
        return ans;
    }
};
