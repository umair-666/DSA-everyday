// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
// The elements can be large so return it modulo 109 + 7.

 class Solution{
  int mod = 1e9+7;
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here    
        vector<long long> ans(n,1), prev(n,1);
        for(int i=1;i<n;i++){
            for(int j=1;j<i;j++){
                ans[j] = (prev[j]+prev[j-1]) % mod;
            }
            prev = ans;
        }
        return ans;
    }
};
