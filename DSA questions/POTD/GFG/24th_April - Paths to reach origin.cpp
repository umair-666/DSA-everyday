// Paths to reach origin
// https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

class Solution{
private:
    vector<vector<int>> memo;
    
    int helper(int x, int y){
        if (x == 0 && y == 0) return 1;
        if (x < 0 || y < 0) return 0;
        
        if (memo[x][y] != -1) return memo[x][y]; // Check if result exists in cache
        
        int left = helper(x - 1, y);
        int down = helper(x, y - 1);
        return memo[x][y] = (left + down) % 1000000007;
    }
public:
    int ways(int x, int y)
    {
        memo.resize(x + 1, vector<int>(y + 1, -1));
        return helper(x,y);   
    }
};
