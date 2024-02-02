// Implement Atoi
// https://www.geeksforgeeks.org/problems/implement-atoi/1

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
          int ans=0;
        int i=(s[0]=='-')?1:0;
        while(i<s.size())
        {
            if(s[i]>='0' &&s[i]<='9') ans=ans*10+(s[i]-'0');
            else
            return -1;

           i++;
        }
        if(s[0]=='-') ans=ans*(-1);
        
        return ans;
    
    }
};
