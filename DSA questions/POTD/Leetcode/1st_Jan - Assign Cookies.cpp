// 455. Assign Cookies
// https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m= s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cnt = 0;
        int cookieIndex = 0;
        while(cnt < n && cookieIndex < m){
            if(s[cookieIndex] >= g[cnt])
                cnt++;
            cookieIndex++;
        }
        return cnt;  
    }
};

// g-> children greed
//s -> cookies
