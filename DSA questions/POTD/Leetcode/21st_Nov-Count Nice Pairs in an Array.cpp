
// 1814 - Count Nice Pairs in an Array

class Solution
{
    int rev(int num)
    {
        int r = 0;
        while (num)
        {
            int d = num % 10;
            r = r * 10 + d;
            num /= 10;
        }
        return r;
    }

public:
    int countNicePairs(vector<int> &nums)
    {

        int count = 0;
        int mod = 1e9 + 7;
        vector<int> arr;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] - rev(nums[i]);
        }

        unordered_map<int, int> mp;
        for (int num : nums)
        {
            count = (count + mp[num]) % mod;
            mp[num]++;
        }
        return count;
    }
};
