// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
       
        vector<int> ans(n, 0); // Initialize the answer vector with zeros.
        stack<int> s; // Use a stack to keep track of indices.

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int prevIndex = s.top();
                s.pop();
                ans[prevIndex] = i - prevIndex;
            }
            s.push(i);
        }

        return ans;
    }
};
