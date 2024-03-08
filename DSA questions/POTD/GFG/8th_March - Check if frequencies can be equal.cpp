// Check if frequencies can be equal
// https://www.geeksforgeeks.org/problems/check-frequencies4211/1

class Solution{
public:	
	bool sameFreq(string s)
	{
	    unordered_map<char,int> mp;
	    for(char c : s){
	        mp[c]++;
	    }
	
        for(char ch = 'a'; ch<='z'; ch++){
            unordered_map<char,int>mp1;
            mp[ch]--; 
            for(auto it:mp){
                if(it.second > 0)
                    mp1[it.second]++; 
                if(mp1.size() > 1)
                    break;
            }
            if(mp1.size() == 1)
                return true; 
                
            mp[ch]++; 
        }
        
        return false;
	}
};
