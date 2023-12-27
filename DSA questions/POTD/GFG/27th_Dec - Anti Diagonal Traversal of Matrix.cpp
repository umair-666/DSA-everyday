// Anti Diagonal Traversal of Matrix
// https://www.geeksforgeeks.org/problems/print-diagonally1623/1

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        int n=matrix.size();
        
        vector<int>ans;
        
         for(int i = 0; i < n; i++){
            int r = 0;
            for(int j = i; j >= 0; j--){
                ans.push_back(matrix[r][j]);
                r++;
            }
        }
        
        for(int i = 1; i < n; i++){
            int r = i;
            for(int j = n-1; j >= i; j--){
                ans.push_back(matrix[r][j]);
                r++;
            }
        }
        return ans;
    }
};
