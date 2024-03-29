// Euler Circuit in an Undirected Graph
// https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

class Solution {
public:
	bool isEularCircuitExist(int v, vector<int>adj[]){
	    //if number of edge from all vertex is even so it will form euler circuit elese no
	    for(int i=0;i<v;i++){
	        if((adj[i].size())&1) return false;
	    }
	    return true;
	}

};
