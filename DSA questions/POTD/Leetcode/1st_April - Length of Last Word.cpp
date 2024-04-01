// 58. Length of Last Word
// https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int n = s.size();
        int s_length = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ' ') {
                if (s_length > 0) break; // Skip trailing spaces
            } else {
                s_length++;
            }
        }
        return s_length;
    }
};
