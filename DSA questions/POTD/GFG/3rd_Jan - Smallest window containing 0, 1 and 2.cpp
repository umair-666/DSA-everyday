// Smallest window containing 0, 1 and 2
// https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

class Solution {
  public:
    int smallestSubstring(string s) {
     
        int i=0 ,  j=0;
        int ans=INT_MAX;
        
        vector<int>v(3,INT_MAX);
        
        for(int i = 0;i< s.length();i++){
           v[s[i]-'0'] = i;
           int maxi,mini;
           if(v[0] != INT_MAX && v[1]!=INT_MAX && v[2] != INT_MAX){
               maxi = max(v[0], max(v[1],v[2]));
               mini = min(v[0], min(v[1],v[2]));
               ans = min(ans, maxi-mini+1);
           }
       }
        return (ans==INT_MAX) ? -1 : ans;
   
    }
};
