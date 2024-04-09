// 2073. Time Needed to Buy Tickets
// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> queue;

        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;

        while (!queue.empty()) {
            time++;

            int front = queue.front();
            queue.pop();

            tickets[front]--;

            // If person k bought all their tickets, return time
            if (k == front && tickets[front] == 0) {
                return time;
            }
            
            if (tickets[front] != 0) {
                queue.push(front);
            }
        }

        return time;
    }
};
