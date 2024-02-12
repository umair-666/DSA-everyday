// 169. Majority Element
//  https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12

// SC = O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele = 0;
        for(int num : nums){
            if(cnt == 0){
                ele = num;
                cnt++;
            }
            else if(ele == num){
                cnt++;
            }
            else
            cnt--;
        }

        return ele;
    }
};

// SC = O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(auto it : nums)
            mp[it]++;

        int ele = 0;
        for(auto it : mp){
            if(it.second > n/2)
                ele = it.first;
        }

        return ele;
    }
};
