// 76. Minimum Window Substring
//  https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04

class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        if(n<m) return "";  // edge case

        int mini = INT_MAX;  unordered_map<char,int> mp;
        int i = 0, j= 0, start = 0; 
       

        for(char c : t)
            mp[c]++;
        
        int count = mp.size();

        while(j<n){

            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(count == 0){
                while(count == 0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]] == 1){
                            count++;
                            if(j-i+1 < mini){
                                mini = j-i+1;
                                start = i;
                            }
                        }
                    }
                    i++;
                }
            }
            j++;
        }

    if(mini == INT_MAX) return "";

    return s.substr(start,mini);

    }
};
