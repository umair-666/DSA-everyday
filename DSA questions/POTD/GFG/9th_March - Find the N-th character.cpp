// Find the N-th character
// https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1

// TLE:
class Solution{ 
  public:
    char nthCharacter(string s, int r, int n) {
        
        while(r--){
            string ans = "";
            for(int i=0;i< s.size();i++){
                if(s[i] == '0')
                    ans +="01";
                else
                    ans +="10";
            }
            s = ans;
        }
      
        return s[n];
    }
};

// Optimsed:
class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
            if(r==0)  return s[n];
            
            string ss;
            int ind = n/(1<<r);
            if(s[ind]=='1')  ss="10";
            else  ss="01";
            
            return nthCharacter(ss, r-1, n % (1<<r) );
        }
    };
