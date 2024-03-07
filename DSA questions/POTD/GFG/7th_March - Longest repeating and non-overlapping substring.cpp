// Longest repeating and non-overlapping substring
// https://www.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring3421/1

class Solution {
  public:
    string longestSubstring(string s, int n) {
        string answer;
        int i=0,j=0;
        int cur=0;
        while(i<n && j<n)
        {
            string str = s.substr(i,j-i+1);
            if(s.find(str,j+1)!=string::npos)
            {
                int len = str.size();
                if(len>cur)
                {
                    cur=len;
                    answer=str;
                }
                j++;
            }
            else
                i++;
        }
        if(answer.empty())
            return "-1";
        return answer;
    }
};
