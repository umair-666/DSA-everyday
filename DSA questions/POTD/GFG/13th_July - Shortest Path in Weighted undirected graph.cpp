// Shortest Path in Weighted undirected graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9), parent(n+1);
        
        for(int i=1;i<=n;i++) parent[i] = i;
        vector<int>vis(n+1,0);
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto &it:adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n]==1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }
};
