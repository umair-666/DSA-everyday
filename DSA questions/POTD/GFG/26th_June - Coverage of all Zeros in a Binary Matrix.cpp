// Coverage of all Zeros in a Binary Matrix
// https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1



class Solution {
    void upper(vector<vector<int>>& matrix, int& counter, int i, int j) {
        if (i > 0 && matrix[i-1][j] == 1) {
            counter++;
        }
    }
    
    void lower(vector<vector<int>>& matrix, int& counter, int i, int j) {
        if (i < matrix.size() - 1 && matrix[i+1][j] == 1) {
            counter++;
        }
    }
    
    void left(vector<vector<int>>& matrix, int& counter, int i, int j) {
        if (j > 0 && matrix[i][j-1] == 1) {
            counter++;
        }
    }
    
    void right(vector<vector<int>>& matrix, int& counter, int i, int j) {
        if (j < matrix[0].size() - 1 && matrix[i][j+1] == 1) {
            counter++;
        }
    }


  public:
    int findCoverage(vector<vector<int>>& matrix) {
          int counter = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    upper(matrix, counter, i, j);
                    lower(matrix, counter, i, j);
                    left(matrix, counter, i, j);
                    right(matrix, counter, i, j);
                }
            }
        }
        return counter;
    }
};
