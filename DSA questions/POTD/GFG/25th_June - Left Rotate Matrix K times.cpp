// Left Rotate Matrix K times
// https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();
         if (n == 0) return mat;
         int m = mat[0].size();
         k = k % m;
        
        while(k>0){
            int i=0;
            while(n>i){
                int value = mat[i][0];
                mat[i].erase(mat[i].begin() + 0);
                mat[i].push_back(value);
                i++;
            }
            k--;
        }
        return mat;
    }
};

