// 1578. Minimum Time to Make Rope Colorful
// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime){
        int cnt = 0,  prev = 0;;
        for(int i=1;i<colors.size();i++){
            if(colors[prev] != colors[i]){
                prev = i;
            }
            else if(neededTime[prev] < neededTime[i]){
                cnt +=neededTime[prev];
                prev = i;
            }
            else
                cnt +=neededTime[i];
        }
        return cnt;
    }
};
