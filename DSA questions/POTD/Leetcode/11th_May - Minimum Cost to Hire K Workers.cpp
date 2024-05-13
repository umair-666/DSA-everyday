// 857. Minimum Cost to Hire K Workers
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/?envType=daily-question&envId=2024-05-11

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double totalCost = numeric_limits<double>::max();
        double currentTotalQuality = 0;
        vector<pair<double, int>> wageToQualityRatio;

        for (int i = 0; i < n; i++) {
            wageToQualityRatio.push_back(
                {static_cast<double>(wage[i]) / quality[i], quality[i]});
        }

        sort(wageToQualityRatio.begin(), wageToQualityRatio.end());

        priority_queue<int> highestQualityWorkers;

        for (int i = 0; i < n; i++) {
            highestQualityWorkers.push(wageToQualityRatio[i].second);
            currentTotalQuality += wageToQualityRatio[i].second;

            if (highestQualityWorkers.size() > k) {
                currentTotalQuality -= highestQualityWorkers.top();
                highestQualityWorkers.pop();
            }
          
            if (highestQualityWorkers.size() == k) {
                totalCost = min(totalCost, currentTotalQuality *
                                               wageToQualityRatio[i].first);
            }
        }
        return totalCost;
    }
};
                                                                                                                                                                                        // If we have more than k workers,
                                                                                                                                                                                                    // remove the one with the highest quality
                                                                                                                                                                                                                if (highestQualityWorkers.size() > k) {
                                                                                                                                                                                                                                currentTotalQuality -= highestQualityWorkers.top();
                                                                                                                                                                                                                                                highestQualityWorkers.pop();
                                                                                                                                                                                                                                                            }

                                                                                                                                                                                                                                                                        // If we have exactly k workers,
                                                                                                                                                                                                                                                                                    // calculate the total cost and update if it's the minimum
                                                                                                                                                                                                                                                                                                if (highestQualityWorkers.size() == k) {
                                                                                                                                                                                                                                                                                                                totalCost = min(totalCost, currentTotalQuality *
                                                                                                                                                                                                                                                                                                                                                               wageToQualityRatio[i].first);
                                                                                                                                                                                                                                                                                                                                                                           }
                                                                                                                                                                                                                                                                                                                                                                                   }
                                                                                                                                                                                                                                                                                                                                                                                           return totalCost;
                                                                                                                                                                                                                                                                                                                                                                                               }
                                                                                                                                                                                                                                                                                                                                                                                              };
