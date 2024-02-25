// Reach a given score
// https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n) {
        // Initialize a vector to store the number of ways to make change for each amount
        vector<int> total(n + 1, 0);
        total[0] = 1;

        // Update the vector based on the coins available
        vector<int> scores = {3, 5, 10};
        for (int s : scores) {
            for (int i = s; i <= n; i++) {
                total[i] += total[i - s];
            }
        }

        // Return the number of ways to make change for the given amount
        return total[n];
    }
};

