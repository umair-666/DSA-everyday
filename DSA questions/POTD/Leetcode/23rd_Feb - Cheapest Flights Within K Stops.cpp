// 787.Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create a graph
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int , pair<int,int>>> q;
        q.push({0,{src,0}});     //{stops,{node,dist}};

        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        while(!q.empty()){
            auto it = q.front(); q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)   continue;     // We stop the process as soon as the limit for the stops reaches

            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edgeWt = iter.second;

                 // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.
                if(cost + edgeWt < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {adjNode ,cost + edgeWt}});
                }
            }
        }
        if(dist[dst] == 1e9)    return -1;

        return dist[dst];
    }
};
