// 1550. Three Consecutive Odds
// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() <3) return false;
        for(int i=0;i<arr.size()-2;i++){
            if(arr[i]&1 && arr[i+1]&1 && arr[i+2]&1)
            return true;
        }
        return false;
    }
};
