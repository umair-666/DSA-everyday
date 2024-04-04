// Sum of all substrings of a number
// https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

class Solution{
    public:
    int mod = 1e9 + 7;
    long long sumSubstrings(string s){
        
        int n = s.size();
        long long ans = s[0] - '0';
        long long prev = ans, curr;
        for(int i = 1; i < n; i++)
        {
            curr = ((i + 1) * (s[i] - '0') + 10 * prev) % mod;
            prev = curr;
            ans = (ans + curr) % mod;
        }
        return ans;
    }
};
