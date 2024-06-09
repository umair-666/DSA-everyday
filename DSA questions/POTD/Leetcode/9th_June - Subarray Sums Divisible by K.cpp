// 974. Subarray Sums Divisible by K
// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        vector<int> fre(k, 0);
        fre[0] = 1;
        int res = 0;
        long long sum = 0;
        for(int x: nums){
            sum += x ;
            int rem = (sum % k + k ) %k;
            if(fre[rem] > 0) res += fre[rem];
            fre[rem]++;
        }
        return res;
    }
};
