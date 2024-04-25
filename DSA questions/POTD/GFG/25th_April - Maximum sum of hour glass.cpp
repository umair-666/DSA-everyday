// Maximum sum of hour glass
// https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int sum=-1;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                int curr = mat[i][j] + mat[i][j+1]+mat[i][j+2]
                        + mat[i+1][j+1]
                        + mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
                        
                sum = max(curr,sum);
            }
        }
        return sum;
    }
};
