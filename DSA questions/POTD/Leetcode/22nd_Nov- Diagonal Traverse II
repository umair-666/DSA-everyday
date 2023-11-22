
//1424 -  Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        int n = nums.size();
        
        // Variables to keep track of the maximum sum, total size, and result index
        int maxSum = 0, size = 0, index = 0;
        
        // Create a map to store elements with the same diagonal sum
        vector<vector<int>> map(100001);
        
        // Iterate through each row in the 2D vector
        for (int i = 0; i < n; i++) {
            // Update the total size with the size of the current row
            size += nums[i].size();
            
            // Iterate through each element in the current row
            for (int j = 0; j < nums[i].size(); j++) {
                // Calculate the diagonal sum for the current element
                int sum = i + j;
                
                // Store the element in the map based on its diagonal sum
                map[sum].push_back(nums[i][j]);
                
                // Update the maximum diagonal sum encountered so far
                maxSum =  max(maxSum, sum);
            }
        }
        // Create a vector to store the result
        vector<int> res(size);
        
        // Iterate through the map elements in reverse order of diagonal sums
        for (int i = 0; i <= maxSum; i++) {
            vector<int>& cur = map[i];
            
            // Iterate through the elements in the current diagonal sum
            for (int j = cur.size() - 1; j >= 0; j--) {
                // Fill the result vector with elements from the current diagonal sum
                res[index++] = cur[j];
            }
        }
        
        return res;
    }
};
