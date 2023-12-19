// 661. Image Smoother
// https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19

class Solution {
    int mean(int i , int j, vector<vector<int>>& img){
        
        int n = img.size();
        int m = img[0].size();
       
        int sum = 0, cnt = 0;

         //traverse neighbouring rows in all 8 directions + self cell
         for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                int nr = i + x;
                int nc = j + y;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    sum += img[nr][nc];
                    cnt++;
                }
            }
        }
        return sum / cnt;   
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int n = img.size();
        int m = img[0].size();
        
        vector<vector<int>> res(n,vector<int>(m));

        for(int i=0;i<img.size();i++){
            for(int j = 0;j<img[0].size();j++){
                res[i][j] = mean(i,j,img);
            }
        }
        return res;
    }
};





