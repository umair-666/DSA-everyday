// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19

class Solution {
public:
    int n, m;
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        grid[i][j] = '0'; // Mark the cell as visited

        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (isValid(ni, nj) && grid[ni][nj] == '1') {
                dfs(ni, nj, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int islands = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};
