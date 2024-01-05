// Count possible ways to construct buildings
// https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1

 class Solution{
	public:
	int mod = 1e9+7;
	int TotalWays(int N){
	    
	    if(N==1)    return 4;
	    if(N==2)    return 9;
	    
	    
	    int a = 2, b = 3, s = 0;
	   
	    for(int i = 3;i<=N;i++){
	        int c = (a+b) %mod;
	        s =  (1LL * c * c) % mod; 
	        a = b;
	        b = c;
	    }
	    return s;
	    
	    // N = 1 -> 4
	    // N = 2 -> 9
	    // N = 3 -> 25
	    // N = 4 -> 64 
	}
};
