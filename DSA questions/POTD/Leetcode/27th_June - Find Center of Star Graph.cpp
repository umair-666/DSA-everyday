// 1791. Find Center of Star Graph
// https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int a = edges[0][0];    //1
        int b = edges[0][1];    //2
        int c = edges[1][0];    //2
        int d = edges[1][1];    //3

        if(a==c || a==d) return a;
        if(b==c || b==d) return b;

        return -1;
    }
};
