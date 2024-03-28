// City With the Smallest Number of Neighbors at a Threshold Distance
// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        //make graph
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        for( auto it : edges){
            int u = it[0];
            int v = it[1];
            dist[u][v] = it[2];
            dist[v][u] = it[2];
        }
        //make diagonals 0
        for(int i=0;i<n;i++) dist[i][i] = 0;
        
        //F.W Algo
        for(int k = 0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int cntCity = n;
        int cityNo = -1;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n;adjCity++){
                if(dist[city][adjCity] <= distanceThreshold)
                    cnt++;
                }
                
                if(cnt <=cntCity){
                    cntCity = cnt;
                    cityNo = city;
                }
            }
         return cityNo;
    }
};
