// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

//Approach 1 : (TLE)

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       
       int i = startRow, j = startColumn;
        if(i < 0 || j < 0 || i >= m || j >= n) return 1; //moved out of box;

        if(maxMove == 0)    return 0; //maxMoves finished

        return  findPaths(m,n,maxMove - 1,startRow, startColumn - 1) + 
                findPaths(m,n,maxMove - 1,startRow - 1, startColumn) + 
                findPaths(m,n,maxMove - 1,startRow, startColumn + 1) + 
                findPaths(m,n,maxMove - 1,startRow + 1, startColumn);

    }
};

