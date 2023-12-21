// 1637. Widest Vertical Area Between Two Points Containing No Points
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(int i=0;i<points.size();i++){
            x.push_back(points[i][0]);
        }
        
        int maxi = 0;
        sort(x.begin(),x.end());

        for(int a = 0;a<points.size()-1;a++){
            if(x[a+1] - x[a] > maxi)
                maxi = x[a+1] - x[a];
        }
        return maxi;

    }
};
