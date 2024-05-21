// 78. Subsets
// https://leetcode.com/problems/subsets/description/?envType=daily-question&envId=2024-05-21

class Solution {
private:
    void solvesub(vector<int> nums, vector<int> output,  int index, vector<vector<int> >& ans){

        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return ;}

        //exclude call
        solvesub(nums, output, index+1, ans);

        //include
        int element = nums[index];
        output.push_back(element);
        solvesub(nums, output, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solvesub(nums, output, index, ans);
        return ans;

    }
};
