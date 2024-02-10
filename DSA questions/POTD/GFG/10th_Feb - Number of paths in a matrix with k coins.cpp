// Number of paths in a matrix with k coins
//  https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

class Solution {
    
    int dp[100][100][100] ;
    int N ;
    
    int solve( int i , int j , int k , vector<vector<int>> &arr )
{
        if( i == N - 1 && j == N - 1 && k == arr[i][j] ) return 1 ;
        if( k <= 0 or i >= arr.size()  or j >= arr.size()  ) return 0 ;
        
        if( dp[i][j][k] != -1 ) return dp[i][j][k] ;
        
        return dp[i][j][k]  = solve( i + 1 , j , k - arr[i][j] , arr ) + solve( i , j+1 , k - arr[i][j] , arr ) ;
        
    }
    
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        N = n ;
        memset( dp , -1 , sizeof(dp) ) ;
        return solve( 0 , 0 , k , arr ) ;
    }
};
