// 2000. Reverse Prefix of Word
// https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch); // Find ch
        reverse(word.begin(), word.begin() + index + 1 ); // Reverse prefix
        return word;
    }
};
