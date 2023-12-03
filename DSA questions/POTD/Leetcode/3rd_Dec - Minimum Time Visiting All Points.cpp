// 1266. Minimum Time Visiting All Points
// https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2023-12-03

class Solution {

    int findTime(vector<int> &from , vector<int> &to){
        int x = abs(from[0] - to[0]);
        int y = abs(from[1] - to[1]);

        return max(x,y);
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int min_time = 0;

        for(int i=1;i<points.size();i++){
            min_time += findTime(points[i-1] , points[i]);
        }

        return min_time;
    }
};
