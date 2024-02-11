// 1463. Cherry Pickup II
//  https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11

// TC = O(M^2) -> robots can be anywhere in grid
// SC = O(N * M^2) -> 3d dp array size

class Solution {
public:
    int numRows, numCols;
    
    int maxCherries(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& memo) {
        
        if (row == numRows || col1 < 0 || col1 >= numCols || col2 < 0 || col2 >= numCols) return 0;
        
        if (memo[row][col1][col2] != -1) return memo[row][col1][col2];
        
        int cherries = (col1 != col2) ? grid[row][col1] + grid[row][col2] : grid[row][col1];
        int nextCherries = 0;

        for (int d1 : {col1 - 1, col1, col1 + 1}) {
            for (int d2 : {col2 - 1, col2, col2 + 1}) {
                nextCherries = max(nextCherries, maxCherries(row + 1, d1, d2, grid, memo));
            }
        }
        
        return memo[row][col1][col2] = cherries + nextCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        numRows = grid.size();
        numCols = grid[0].size();
        
        vector<vector<vector<int>>> memo(numRows, vector<vector<int>>(numCols, vector<int>(numCols, -1)));
        return maxCherries(0, 0, numCols - 1, grid, memo);
    }
};
