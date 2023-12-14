// 2482. Difference Between Ones and Zeros in Row and Column
// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/?envType=daily-question&envId=2023-12-14

class Solution {
    
    int countOnes2(int j , vector<vector<int>>& grid){
        int cnt = 0;
        for(int i = 0;i<grid.size();i++){
            if(grid[i][j] == 1)
                cnt++;
        }
        return cnt;
    }
   int countOnes1(int i , vector<vector<int>>& grid){
        int cnt = 0;
        for(int j = 0;j<grid[i].size();j++){
            if(grid[i][j] == 1)
                cnt++;
        }
        return cnt;
    } 
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rows(n);
        int m = grid[0].size();
        vector<int> cols(m);

        for(int i=0;i<n;i++){
            rows[i] = countOnes1(i,grid);
        }

        for(int j=0;j<m;j++){
            cols[j] = countOnes2(j,grid);
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for(int i=0;i<n;i++){
            int onesRows = rows[i]; //2
            for(int j=0;j<m;j++){
                int oneCols = cols[j];//1 
                
                int zeroRows = grid[i].size() - onesRows; //1
                int zeroCols = grid.size() - oneCols;//2
                
                int diff = onesRows + oneCols - zeroRows - zeroCols;
                ans[i][j] = diff;
            }  
        }
        return ans;
    }
};







