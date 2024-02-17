// 1642. Furthest Building You Can Reach
// https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17

 class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
       
        priority_queue<int> pq;

        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
                pq.push(-diff); // Push negative of height difference for max heap

            if (pq.size() > ladders) { // If number of elements in pq exceed available ladders
                bricks += pq.top(); // Add the largest difference to bricks
                pq.pop(); // Remove the largest difference from pq
            }

            if (bricks < 0)
                return i; // Return furthest index reached if bricks become negative
        }

        return heights.size() - 1; // Return last index if all buildings can be reached
    }
};
