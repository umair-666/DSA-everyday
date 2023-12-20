// 2706. Buy Two Chocolates
// https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20

// Approach 1: TC = O(NlogN) SC = O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin() , prices.end());
        int left_over = money - (prices[0] + prices[1]);
        return left_over < 0 ? money : left_over;
    }
};


// Approach 2 : TC = O(N) SC = O(1)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int x = INT_MAX,y = INT_MAX;
        for(auto &i: prices){
            if(x>i){
                y = x;
                x = i;
            }else if(y>i){
                y = i;
            }
        }
        if(x+y>money)return money;
        return money-x-y;
    }
};
