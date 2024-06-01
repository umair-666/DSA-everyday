// Odd Even Problem
// https://www.geeksforgeeks.org/problems/help-nobita0532/1


class Solution {
  public:
    string oddEven(string s) {
        int sum = 0;
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        
        for(auto it:mp) {
            if(it.first%2 == 1 && it.second%2 == 1) { // odd
                sum += 1;
            }
            else if(it.first%2 == 0 && it.second%2 == 0) { //even
                sum += 1;
            }
        }
        
        string ans="";
        if(sum%2 == 1)
            ans += "ODD";
        else if(sum%2 == 0)
           ans += "EVEN";
           
        return ans;
    }
};
