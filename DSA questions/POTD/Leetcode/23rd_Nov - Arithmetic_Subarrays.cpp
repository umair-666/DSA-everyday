// 1630. Arithmetic Subarrays

//  TC = O(m * (r[i] - l[i]) * log(r[i] - l[i]))
//  SC = O(m)

class Solution {

    bool helper(vector<int> nums , int s , int e){

        sort(nums.begin() + s , nums.begin()+ e + 1);
        int diff = nums[s+1] - nums[s];
        for(int i = s+1 ; i< e ; i++){
            if(nums[i+1] - nums[i] != diff)
                return 0;
        }
        return 1;

    }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int m = l.size();
        vector<bool> ans(m);
    
        for(int i=0;i<m;i++){
            ans[i]  = helper(nums,l[i] , r[i]);
        }

        return ans;

    }
};
