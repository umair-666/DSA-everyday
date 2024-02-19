// Game with String
// https://www.geeksforgeeks.org/problems/game-with-string4100/1

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        
        while(k>0){
            char maxString;
            int maxCount=0;
            for(auto it:mp){
                maxCount=max(maxCount,it.second);
                if(maxCount==it.second){
                    maxString=it.first;
                }
            }
            mp[maxString]--; // in every iteration, max occurence wala minus hora
            k--;
        }
        
        int sum = 0;
        for(auto it: mp){
            sum += it.second*it.second;
        }
        return sum;
    }
};
