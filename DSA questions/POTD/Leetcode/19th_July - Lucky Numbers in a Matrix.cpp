// 1380. Lucky Numbers in a Matrix
// https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> mini , maxi, ans;

        //max_col
        for(int j = 0 ; j < matrix[0].size();j++){
            int mx = INT_MIN;
            for(int i = 0 ; i < matrix.size();i++){
                    mx = max(mx,matrix[i][j]);
            }
            maxi.push_back(mx);
        }

        //min_row
        for(int i = 0 ; i < matrix.size();i++){
            int mn = INT_MAX;
            for(int j = 0 ; j < matrix[i].size();j++){
                    mn = min(mn,matrix[i][j]);
            }
            mini.push_back(mn);
        }

        for(int i = 0 ; i < matrix.size();i++){
            for(int j = 0 ; j < matrix[i].size();j++){
                if(matrix[i][j] == mini[i] && matrix[i][j] == maxi[j])
                    ans.push_back(matrix[i][j]);
            }
        }

        return ans;

    }
};
