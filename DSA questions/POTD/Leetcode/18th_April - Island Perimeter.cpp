// 463 . Island Perimeter
// https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18

// DFS:
class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base cases for DFS recursion
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) {
            return 1; // Water contributes 1 to perimeter
        }
        if (grid[r][c] == -1) {
            return 0; // Already visited land cell
        }

        // Mark cell as visited
        grid[r][c] = -1;

        // Explore neighbours (up, down, left, right)
        return (dfs(grid, r + 1, c) +
                dfs(grid, r - 1, c) +
                dfs(grid, r, c + 1) +
                dfs(grid, r, c - 1));
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += dfs(grid, r, c);
                }
            }
        }

        return perimeter;
    }
};

// ITERATIVE:

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    perimeter += 4;
                    if (r > 0 && grid[r-1][c] == 1) {
                        perimeter -= 2;
                    }
                    if (c > 0 && grid[r][c-1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        
        return perimeter;
    }
};
