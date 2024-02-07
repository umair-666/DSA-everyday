// Min distance between two given nodes of a Binary Tree
//  https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution{
    void traverse(Node* root, unordered_map<int, list<int>>& adj, unordered_map<int, int>& dist) {
        if(root == NULL) {
            return;
        }
        if(root -> left) {
            adj[root -> data].push_back(root -> left -> data);
            adj[root -> left -> data].push_back(root -> data);
            dist[root -> data] = INT_MAX;
            dist[root -> left -> data] = INT_MAX;
        }
        if(root -> right) {
            adj[root -> data].push_back(root -> right -> data);
            adj[root -> right -> data].push_back(root -> data);
            dist[root -> data] = INT_MAX;
            dist[root -> right -> data] = INT_MAX;
        }
        traverse(root -> left, adj, dist);
        traverse(root -> right, adj, dist);
    }
    
    public:
    int findDist(Node* root, int a, int b) {
         // Dijkstra's algo
        unordered_map<int, list<int>> adj;
        unordered_map<int, int> dist; 
        traverse(root, adj, dist);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, a});
        dist[a] = 0;
        
        while(!pq.empty()) {
            auto d = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            
            for(auto nbr: adj[node]) {
                if(1 + d < dist[nbr]) {
                    dist[nbr] = 1 + d;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
    
        return dist[b];
    }
};
