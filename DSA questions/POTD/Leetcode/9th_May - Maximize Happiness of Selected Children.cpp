// 3075. Maximize Happiness of Selected Children
// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long totalHappinessSum = 0;
        int turns = 0;
        
        // Calculate the maximum happiness sum
        for(int i = 0; i < k; i++) {
            // Adjust happiness and ensure it's not negative
            totalHappinessSum += max(happiness[i] - turns, 0);  

            // Increment turns for the next iteration
            turns++; 
        }
        
        return totalHappinessSum;
    }
};
