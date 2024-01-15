// 2225.Find Players With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15


//TC = O(NlogN)  SC = O(N)
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> answer;

        map<int,int> mp, win;

        for(auto it : matches){
            mp[it[1]]++; //losers
        }

        for(auto it : matches){
            win[it[0]]++; //winners
        }

        vector<int> winners, losers;

        for(auto it : mp){
            if(it.second == 1) //have lost one match
                losers.push_back(it.first);
        }


        for(auto it : win){
            if(mp.find(it.first) == mp.end()) //check for winners-> if not in mp then they are winners
                winners.push_back(it.first);
        }

        answer.push_back(winners);
        answer.push_back(losers);

        return answer;
    }
};
