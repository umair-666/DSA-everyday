// Nuts and Bolts Problem
// https://www.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        
      unordered_map<char,int>mp;
       char a[]={'!','#','$','%','&','*','?','@','^'};
       
       for(int i=0;i<9;i++)
       {
           mp[a[i]]=i;
       }
       vector<int>v(n);
       for(int i=0;i<n;i++)
       {
           v[i]=mp[nuts[i]];
       }
       
       sort(v.begin(),v.end());
       
       vector<int>v1(n);
       
       for(int i=0;i<n;i++)
       {
           v1[i]=mp[bolts[i]];
       }
       
       sort(v1.begin(),v1.end());
        for(int i=0;i<n;i++)
       {
           nuts[i]=a[v[i]];
       }
        for(int i=0;i<n;i++)
       {
           bolts[i]=a[v1[i]];
       }   
    }
};
