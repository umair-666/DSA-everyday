// Determinant of a Matrix
// https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

// Tip : Use Cramer's Rule.
class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
         if(n==1)   return matrix[0][0];
         
         vector<vector<int>> submatrix(n-1,vector<int>(n-1));
         int ans = 0;
         for(int i=0;i<n;i++){
             for(int j=1;j<n;j++){
                 int x = 0;
                 for(int k=0;k<n;k++){
                     if(k==i)   continue;
                     submatrix[j-1][x++] = matrix[j][k];
                 }
             }
             ans +=(matrix[0][i]* determinantOfMatrix(submatrix, n-1)*((i&1) == 1 ? -1 : 1));
         }
         return ans;
    }
};
