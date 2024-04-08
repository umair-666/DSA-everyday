// Optimal Strategy For A Game
// https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1

class Solution{
    long long win(int arr[],int n, int i, int j,int turn,vector<vector<long long>> &dp){
        
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(turn){
            return dp[i][j] = max(arr[i]+win(arr,n,i+1,j,0,dp), arr[j]+win(arr,n,i,j-1,0,dp)); // my turn
        }
        else{
            return dp[i][j] = min(win(arr,n,i+1,j,1,dp), win(arr,n,i,j-1,1,dp)); // opponent turn
        }
}
    public:
    long long maximumAmount(int n, int arr[]){
        vector<vector<long long>> dp (n,vector<long long>(n,-1));
        return win(arr,n,0,n-1,1,dp);
    }
};
