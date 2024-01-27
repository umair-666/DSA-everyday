// Brackets in Matrix Chain Multiplication
// https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution{
     pair<int,string> solve(int i,int j,int p[]){
        if(i==j){
            string curr = "";
            curr += 'A' + i-1; 
            return {0,curr};
        }
        
        if(dp[i][j].second != "") return dp[i][j];
        
        int val = INT_MAX;
        string s = "";
        
        for(int k=i;k<j;k++){
            pair<int,string> a =  solve(i,k,p);
            pair<int,string> b =  solve(k+1,j,p);
            int q = p[i-1]*p[j]*p[k] + a.first + b.first;
            if(q<val){
                val = q;
                s = "(" + a.second + b.second + ")";
            }
        }
        return dp[i][j] = {val,s};
     }
public:
    pair<int,string> dp[27][27];
    string matrixChainOrder(int p[], int n){
         return solve(1,n-1,p).second;
    }
};
