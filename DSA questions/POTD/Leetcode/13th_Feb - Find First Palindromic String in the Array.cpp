// 2108. Find First Palindromic String in the Array
//  https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

// Approach 1 :
class Solution {
    bool isPalindrome(string str){
        int s = 0, e = str.size()-1;
        while(s<e){
            if(str[s++] != str[e--])
                return 0;
        }
        return 1;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            if(isPalindrome(it))
                return it;
        }
        return "";
    }
};

// Approach 2:
class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            string s = it;
            reverse(s.begin(), s.end());
            if(s==it)
                return it;
        }
        return "";
    }
};
