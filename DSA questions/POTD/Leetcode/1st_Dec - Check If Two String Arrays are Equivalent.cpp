// 1662. Check If Two String Arrays are Equivalent
// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=daily-question&envId=2023-12-01

 class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string s = "", t = "";
        for(int i=0;i<word1.size();i++){
            s +=word1[i];
        }

         for(int i=0;i<word2.size();i++){
            t +=word2[i];
        }

        return s == t;
        
    }
};
