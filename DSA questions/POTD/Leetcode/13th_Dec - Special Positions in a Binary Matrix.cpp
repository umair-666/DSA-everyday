// 1582. Special Positions in a Binary Matrix
// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13

class Solution {
private:
    int checkRow(int i, vector<vector<int>>& mat){
        int index = -1;
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j] == 1){
                if(index != -1)
                    return -1;
                else
                    index = j;
            }
        }
        return index;
    }

    bool checkColumn(int i , vector<vector<int>>& mat, int index){
        for(int j = 0;j < mat.size();j++){
            if(mat[j][index] == 1 && j!= i)
                return false;
        }

        return true;
    }
public:
    int numSpecial(vector<vector<int>>& mat) {
       
        int n = mat.size();
        
        int cnt = 0;

        for(int i = 0;i<n;i++){
            int idx = checkRow(i,mat);
            if(idx >= 0 && checkColumn(i, mat,idx))
                cnt++;
        }

        return cnt;
    }
};
