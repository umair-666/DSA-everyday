// Print matrix in diagonal pattern
// https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int cnt = 0;
        int n = mat.size();
        vector<int> ans;
         
        for(int i=0;i<n;i++){
            int index = i;
            if(cnt % 2 == 0){
                // j ko increase
                // index ko decrease
                for(int j=0;j<=i;j++){
                    ans.push_back(mat[index][j]);
                    index--;
                }
            }
            else{
                index = i;
                for(int j=0;j<=i;j++){
                    ans.push_back(mat[j][index]);
                    index--;
                }
            }
            cnt++;
        }
         
        for(int i=1;i<n;i++){
            int index = i;
            if(cnt % 2 != 0){
                for(int j=n-1;j>=i;j--){
                    ans.push_back(mat[index][j]);
                    index++;
                }
            }
            else{
                index = n-1;
                for(int j=i;j<n;j++){
                    ans.push_back(mat[index][j]);
                    index--;
                }
            }
            cnt++;
        }
         
        return ans;
    }
};
