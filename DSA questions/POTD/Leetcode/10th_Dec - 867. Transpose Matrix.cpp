// 867. Transpose Matrix
// https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> ans(cols,vector<int>(rows));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                ans[j][i] = matrix[i][j];
            }
        }
        return ans;
    }
};

//flip the rows and cols of given 'matrix' for the ans matrix
