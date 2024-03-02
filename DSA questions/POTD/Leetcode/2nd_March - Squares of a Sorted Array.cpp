// 977. Squares of a Sorted Array
// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=daily-question&envId=2024-03-02

// TC : O(NlogN)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i=0;i < n;i++){
            v[i] = nums[i] * nums[i];
        }

        sort(v.begin(),v.end());
        return v;
    }
};

// TC : O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0, right = n - 1; // Pointers for traversing the input array from both ends
        for (int i = n - 1; i >= 0; i--) {
            int squareLeft = nums[left] * nums[left];
            int squareRight = nums[right] * nums[right];
            
            if (squareLeft > squareRight) {
                result[i] = squareLeft;
                left++;
            } else {
                result[i] = squareRight;
                right--;
            }
        }
        
        return result;
    }
};
