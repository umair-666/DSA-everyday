// Longest subsequence-1
// https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1

 
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        int ans = 0;
        unordered_map<int, int> m;
        
        for (int i=0; i<n; i++) {
            m[a[i]] = 1 + max(m[a[i] - 1], m[a[i] + 1]);
            ans = max(ans, m[a[i]]);
        }
        
        return ans;
    }
};
