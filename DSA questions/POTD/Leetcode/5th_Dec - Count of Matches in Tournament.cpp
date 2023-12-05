// 1688. Count of Matches in Tournament
// https://leetcode.com/problems/count-of-matches-in-tournament/description/?envType=daily-question&envId=2023-12-05

// Approach 1 :-
    
  class Solution {
    public:
        int numberOfMatches(int n) {
            return n-1;
        }
    };

// Approach 2:-
  
class Solution {
  public:
    int numberOfMatches(int n) {
        
        if(n==1)    return 0;

        if( n & 1)              //if odd
            return (n-1)/2 + numberOfMatches((n-1)/2 + 1); 
        else
            return n/2 + numberOfMatches(n/2);
    }
};

//formulate the recursion just according to what the question says
