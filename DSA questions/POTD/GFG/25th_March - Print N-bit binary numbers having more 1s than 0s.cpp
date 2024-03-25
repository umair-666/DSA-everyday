// Print N-bit binary numbers having more 1s than 0s
// https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

class Solution{
public:	
    void solve(int n,int one,int zero,vector<string>&res,string str){
       
       if(str.length()==n){
           res.push_back(str);
           return;
       }
       if(one < n)
       solve(n,one+1,zero,res,str+"1");
      
       if(str.length() < n && zero < one)
       solve(n,one,zero+1,res,str+"0");
       
   }

    vector<string> NBitBinary(int n){
	    vector<string>res;
        solve(n,0,0,res,"");
        return res;
    
	}
};
