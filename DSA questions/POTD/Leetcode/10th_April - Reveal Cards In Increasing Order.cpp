// 950. Reveal Cards In Increasing Order
// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int N = deck.size();
        queue<int> queue;

        for (int i = 0; i < N; i++) {
            queue.push(i);
        }
        
        sort(deck.begin(), deck.end());

        vector<int> result(N);
        for (int i = 0; i < N; i++) {
            // Reveal Card
            result[queue.front()] = deck[i];
            queue.pop();

            // Move next card to bottom
            if (!queue.empty()) {
                queue.push(queue.front());
                queue.pop();
            }
        }
        return result;
    }
};
