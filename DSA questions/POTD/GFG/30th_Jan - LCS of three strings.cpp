// LCS of three strings
// https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1

class Solution {
private:
    int lcsMemo(string& A, string& B, string& C, int n1, int n2, int n3, vector<vector<vector<int>>>& memo) {
        if (n1 == 0 || n2 == 0 || n3 == 0) return 0;

        if (memo[n1][n2][n3] != -1) {
            return memo[n1][n2][n3];
        }

        int ans = 0;

        if (A[n1 - 1] == B[n2 - 1] && B[n2 - 1] == C[n3 - 1]) {
            ans = 1 + lcsMemo(A, B, C, n1 - 1, n2 - 1, n3 - 1, memo);
        } else {
            ans = max(lcsMemo(A, B, C, n1 - 1, n2, n3, memo),
                      max(lcsMemo(A, B, C, n1, n2 - 1, n3, memo),
                          lcsMemo(A, B, C, n1, n2, n3 - 1, memo)));
        }

        memo[n1][n2][n3] = ans;
        return ans;
    }
public:
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
        // Create a 3D memoization array
        vector<vector<vector<int>>> memo(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

        return lcsMemo(A, B, C, n1, n2, n3, memo);
    }

};
