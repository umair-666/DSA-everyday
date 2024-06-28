// 2285. Maximum Total Importance of Roads
// https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);

        for (vector<int>& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long value = 1;
        long long totalImportance = 0;
        for (long long d : degree) {
            totalImportance += (value * d);
            value++;
        }

        return totalImportance;
    }
};
