// 1235.Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        int numJobs = profit.size(); // Number of jobs

        // Combine job details into a tuple and store in 'jobs'
        vector<tuple<int, int, int>> jobs(numJobs);
        for (int i = 0; i < numJobs; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        // Sort jobs based on their end times
        sort(jobs.begin(), jobs.end());

        // Dynamic programming array to store maximum profit at each step
        vector<int> dp(numJobs + 1);

        // Calculate maximum profit for each job
        for (int i = 1; i <= numJobs; ++i) {
            auto [currentEndTime, currentStartTime, currentProfit] = jobs[i - 1];

            // Find the latest non-conflicting job index using binary search
            int latestNonConflictJobIndex = upper_bound(
                jobs.begin(), jobs.begin() + i - 1, currentStartTime,
                [&](int time, const auto& job) -> bool {
                    return time < get<0>(job);
                }) - jobs.begin();

            // Calculate the maximum profit at the current step
            dp[i] = max(dp[i - 1], dp[latestNonConflictJobIndex] + currentProfit);
        }

        return dp[numJobs];
    }
};

// This problem is a standard variation of the Activity Selection Problem. 
// The greedy algorithm works fine for the activity selection problem since all jobs have equal weight. 
// But the greedy approach won’t work with weighted jobs since even a single job may have more profit than all jobs combined.
