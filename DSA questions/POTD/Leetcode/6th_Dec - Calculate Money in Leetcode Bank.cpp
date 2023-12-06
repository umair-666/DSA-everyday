// 1716. Calculate Money in Leetcode Bank
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06

class Solution {
public:
    int totalMoney(int n) {
        int money = 0, week = 0, day = 1;

        for(int i=1;i<=n;i++){
            money +=  (week+day);
            day++;
            if(i%7 == 0){
                week++;
                day = 1;
            }
        }
    return money;
    }
};   
