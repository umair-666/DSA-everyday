// 451. Sort Characters By Frequency
// https://leetcode.com/problems/sort-characters-by-frequency/?envType=daily-question&envId=2024-02-07

class Solution {
public:
    string frequencySort(string s) {
        
        // Count frequencies
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
       
    // Convert the frequency map to a vector of pairs
    vector<pair<char, int>> sortedFreq(mp.begin(), mp.end());

    // Sort the vector based on the frequency count, in descending order
    sort(sortedFreq.begin(), sortedFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    string sortedStr;
    for (auto pair : sortedFreq) {
        sortedStr += string(pair.second, pair.first);
    }
    return sortedStr;
    }
};
