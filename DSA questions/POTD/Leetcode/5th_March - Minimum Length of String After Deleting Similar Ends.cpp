// 1750. Minimum Length of String After Deleting Similar Ends
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        
        while(i < j && s[i] == s[j]){
            char c = s[i];
            while( i <= j && s[i] == c){
                i++;
            }
            while(j >= i && s[j] == c){
                j--;
            }
        }

        return j-i+1;

    }
};
