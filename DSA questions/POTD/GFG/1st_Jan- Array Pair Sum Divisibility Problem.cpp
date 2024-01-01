// Array Pair Sum Divisibility Problem
// https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        
        int n = nums.size();
        
        if(n & 1)   return false;
        
       map<int, int> mp;
        for(auto i : nums)
            mp[i%k]++;
        
        for(auto i : nums){
            int needed = mp[i%k] + mp[ k - (i%k)];
            if(needed & 1) //if odd
               return false;
        }
        
        return true;
    }
};

HINT : look for ` k-nums[i]%k `  the  map
