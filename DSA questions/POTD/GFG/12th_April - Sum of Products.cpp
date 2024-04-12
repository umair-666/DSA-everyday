// Sum of Products
// https://www.geeksforgeeks.org/problems/sum-of-products5049/1

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
         long long ans = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (arr[j] & (1 << i)) count++;
            ans += (1LL << i) * count * (count - 1) / 2;
        }
        return ans;
    }
};
