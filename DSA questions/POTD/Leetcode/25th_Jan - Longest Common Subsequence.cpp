//1143. Longest Common Subsequence
//https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25

// Approach 3: Space Optimized:

class Solution {
public:
    int longestCommonSubsequence(string S1, string S2) {
        
        int n = S1.length();
        int m = S2.length();

        vector<int> prev(m+1 , 0) , curr(m+1 , 0);

        for(int j=0;j<=m;j++)    prev[j] = 0; //first row sab zero hai

        for(int i = 1;i<=n;i++){ 
            for(int j = 1;j<=m;j++){
                
                if(S1[i-1] == S2[j-1])
                     curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max( prev[j] , curr[j-1] ) ;
            }
            prev = curr;
        }
        return prev[m]; 
    }
};

// Approach 2: Memoized :

class Solution {
int f(int i , int j ,string &S1, string &S2, vector<vector<int>> &dp){

    if(i < 0 || j < 0)
        return 0;
    
    if(dp[i][j] != -1)  return dp[i][j]; //check

    if(S1[i] == S2[j])
        return dp[i][j] = 1 + f(i-1 , j-1 , S1 , S2 , dp);
    else
        return dp[i][j] = max( f(i-1 , j , S1, S2, dp) , f(i , j - 1 , S1, S2 , dp) ) ;
}
public:
    int longestCommonSubsequence(string S1, string S2) {
        
        int n = S1.length();
        int m = S2.length();
        vector<vector<int>> dp(n , vector<int>(m , -1)); //declare
        return f(n-1 , m-1, S1, S2, dp);
        //  dp[n-1][m-1];

    }
};


// Approach 1: Simple Recursion (TLE):

class Solution {
int f(int ind1 , int ind2 ,string S1, string S2){

    if(ind1 < 0 || ind2 < 0)
        return 0;

    if(S1[ind1] == S2[ind2])
        return 1 + f(ind1 - 1 , ind2 - 1 , S1 ,S2);
    else
        return max( f(ind1-1 , ind2 , S1, S2) , f(ind1 , ind2 - 1 , S1, S2) ) ;
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();

        return f(n-1 , m-1, text1, text2);
    }
};
