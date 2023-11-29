// Euler circuit and Path
// https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    
	    int odd = 0;
	    for(int i=0;i<V;i++){
	        if(adj[i].size() & 1)
	            odd++;
	    }
	    
	    if(!odd)    return 2;
	    
	    if(odd == 2)    return 1;
	    
	    return 0;
	}
};
