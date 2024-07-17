// Remaining String
// https://www.geeksforgeeks.org/problems/remaining-string3515/1

class Solution {
  public:

    string printString(string s, char ch, int count) {
       int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ch)
        {
            count--;
        }
        if (count == 0)
        {
            return s.substr(i + 1);
        }
    }
    return "";
    }
};
