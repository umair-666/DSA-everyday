// Juggler Sequence
// https://www.geeksforgeeks.org/problems/juggler-sequence3930/1

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
         vector<int>res;
        int  ans= n;
        while(ans!=1){
            res.push_back(ans);
            if(ans%2){
                ans = floor(float(sqrt(ans)*ans));
            }else{
                ans = floor(float(sqrt(ans)));
            }
        }
        res.push_back(ans);
        return res;
    }
};
