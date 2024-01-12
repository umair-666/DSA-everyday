// 1704. Determine if String Halves Are Alike
// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12

class Solution {
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    int countVowels(string t){
        int cnt = 0;
        for(char c : t){
            if(isVowel(c))
                cnt++;
        }
        return cnt; 
    }
public:
    bool halvesAreAlike(string s) {
        int n = s.size();

        string x = s.substr(0,n/2);
        int c1 = countVowels(x);

        string y = s.substr(n/2);
        int c2 = countVowels(y);

        return c1 == c2;
    }
};
