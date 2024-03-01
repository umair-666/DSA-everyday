// 2864. Maximum Odd Binary Number
// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        unordered_map<char,int> mp;
        for(char c : s)
            mp[c]++;
        
        string t;
        for(int i=1;i<mp['1'];i++){
            t +='1';
        }
        for(int i=1;i<=mp['0'];i++){
            t +='0';
        }

        t +='1';

        return t;
    }
};
