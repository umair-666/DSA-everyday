//Course Schedule
//https://www.geeksforgeeks.org/problems/course-schedule/1

class Solution{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) {
       vector<int> adj[V];
        for(auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
	    
	     //use kahns algo-> topo sort using BFS => for checking for cycle
	   
	   // 1.store the indegree of every node in the graph
	   int indegree[V] = {0};
	   for(int i=0;i<V;i++){
	       for(auto it : adj[i])
	        indegree[it]++;
	   }
	   
	   // 2. push every node with indegree = 0 into the queue ( there is always atleast one with indegree = 0)
	   queue<int> q;
	   for(int i=0;i<V;i++){
    	   if(indegree[i] == 0){
    	       q.push(i);
    	   }
	  }
	  
	  vector<int> topo; //answer array
	  
	  // 3. reduce the indegree of every adjacent node by one until it is 0, then push into queue once it indegree of a node  = 0
	  while(!q.empty()){
	      int node = q.front();
	      q.pop();
	      topo.push_back(node);
	      //node is in ypur topo sort
	      //so remove it from indegree
	      for(auto it : adj[node]){
	          indegree[it]--;
	          if(indegree[it] == 0)
	               q.push(it);
	      }
	  }
	  
	   reverse(topo.begin(),topo.end());
	  if(topo.size() == V)  return topo;    // Valid topological order -> you can take the courses => return topo
	  return {};
    }
};
