// Buy and Sell a Share at most twice
//https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        if (n <= 1) {
            return 0;
        }
      
        vector<int> profit(n, 0);

        int maxPrice = price[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxPrice = max(maxPrice, price[i]);
            profit[i] = max(profit[i + 1], maxPrice - price[i]);
        }

        int minPrice = price[0];
        for (int i = 1; i < n; ++i) {
            minPrice = min(minPrice, price[i]);
            profit[i] = max(profit[i - 1], profit[i] + (price[i] - minPrice));
        }

        return profit[n - 1];
    }
};
