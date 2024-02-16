// 1481. Least Number of Unique Integers after K Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(int& x:arr){
            mp[x]++;
        }
        vector<pair<int,int>>dp;
        
        for(auto it:mp){
            dp.push_back(it);
        }

        sort(begin(dp),end(dp),[](auto a,auto b){
            return a.second<b.second;
        });
        
        int count = 0;
        for(auto it:dp){
            if(k>=it.second){
                k-=it.second;
                count++;
            }else{
                break;
            }
        }
        
        return size(dp)-count;
    }
};
