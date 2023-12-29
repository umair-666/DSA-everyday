// Check if a string is repetition of its substring of k-length
// https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1

class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k !=0) return 0;
	    
	    unordered_map<string, int> mp;
	    
	    for(int i = 0; i < n; i = i+k){
	        if(i+k<=n){
	            string t = s.substr(i,k);
	            mp[t]++;
	        }
	    }
         if(mp.size() > 2)  return 0;
         
         return 1;
	}
};
