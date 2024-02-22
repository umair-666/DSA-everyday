// 997.  Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0); // Initialize trust count for each person
        
        for (auto t : trust) {
            int a = t[0]; // Person a trusts person b
            int b = t[1];
            trustCount[a]--; // Decrease trust count for person a
            trustCount[b]++; // Increase trust count for person b
        }

        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1) { // If someone is trusted by everyone except themselves
                return i; // Return that person as the town judge
            }
        }

        return -1;
    }
};
