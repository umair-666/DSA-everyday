// 2971. Find Polygon With the Largest Perimeter
//  https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        long long peri = 0;
        long long res = -1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < peri)
                res = nums[i] + peri;
            peri +=nums[i];
        }

        return res;
    }
};
