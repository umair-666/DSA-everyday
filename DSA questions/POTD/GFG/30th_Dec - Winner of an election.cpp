// Winner of an election
// https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

class Solution{
  public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n){
        
        map<string, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int maxi = 0; string name = "";
        for( auto x : mp){
            if(x.second > maxi){
                name = x.first;
                maxi = x.second;
            }
        }
        
        return {name, to_string(maxi)};      
    }
};
