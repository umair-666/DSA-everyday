// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24


//TC:O(N), SC:O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// TC:O(N) , SC:O(N)
  class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
             mp[nums[i]]++;
        }
        for(auto x:mp){
            if(x.second>1)
            return x.first;
        }
    return -1;
    }
};
