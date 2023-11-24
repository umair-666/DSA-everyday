// 1561 - Maximum Number of Coins You Can Get

 class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n = piles.size();
        sort(piles.begin(),piles.end());
        int me = n/3;

        int sum = 0;

        for(int i = me; i < n; i = i+2){
            sum += piles[i];
        }

        return sum;
    }
};
