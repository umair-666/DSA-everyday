// The Palindrome Pattern
// https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1

class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        // store the index of first column palindrome
        int firstColPalindromeIdx = -1; 
        
        for (int i = 0; i < n; i ++) {
            bool isPalindromeRow = 1, isPalindromeCol = 1;
            for (int j = 0; j < n/2; j ++) {
                if (arr[i][j] != arr[i][n - j - 1]) 
                    isPalindromeRow = 0;
                    
                if (arr[j][i] != arr[n - j - 1][i]) 
                    isPalindromeCol = 0;
            }
            if (isPalindromeRow) 
                return to_string(i) + " R";
            
            if (isPalindromeCol && firstColPalindromeIdx == -1) 
                firstColPalindromeIdx = i;
        } 
        if (firstColPalindromeIdx != -1) 
            return to_string(firstColPalindromeIdx) + " C";
        return "-1";
    }
};
