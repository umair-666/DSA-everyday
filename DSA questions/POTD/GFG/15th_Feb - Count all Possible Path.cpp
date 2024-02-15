// Count all Possible Path
// https://www.geeksforgeeks.org/problems/castle-run3644/1

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	     int n = paths.size();
	     vector<int> deg(n,0);
	     for(int i = 0; i < n; i++){
	         for(int j = 0; j < n; j++){
	             if(paths[i][j])
	                deg[i]++;
	         }
	     }
	     
	     for(int i=0;i<n;i++){
	         if(deg[i] & 1)
	            return 0;
	     }
	     return 1;
	}
	
// 	1. This code checks if it's possible to form an Eulerian path in a graph represented by an adjacency matrix.

// 2. It does this by counting the degrees of each vertex and ensuring that all degrees are even.

// 3. If any vertex has an odd degree, it returns 0, indicating that no Eulerian path is possible.

// 4. Otherwise, it returns 1, indicating that such a path exists.

};
