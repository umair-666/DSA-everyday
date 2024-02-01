// Panagram Checking
// https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1

class Solution{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        
        map<char,int> mp;
        for(int i = 0;i<s.size();i++){
            char c = tolower(s[i]);
            mp[c]++;
        }
        
        for(char x = 'a';x<='z';x++){
            if(mp[x] == 0)
            return 0;
        }
        
       return 1;       
    }
};
