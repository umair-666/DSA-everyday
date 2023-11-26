// Print Pattern
// https://www.geeksforgeeks.org/problems/print-pattern3549/1

class Solution{
public:
     void helper(vector<int>&res, int N, int K){
        
        if(K <= 0){
            res.push_back(K);
            return;
        }
        res.push_back(K);
       
       helper(res, N, K - 5);
       
       res.push_back(K);   
    }
    vector<int> pattern(int N){
        // code here
      vector<int>res;
       
      res.push_back(N);
      
      if(N <= 0)  return res;
      
      helper(res, N, N - 5);
      
      res.push_back(N);
      
      return res;
    }
};
