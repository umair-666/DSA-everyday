// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21

class Solution {
    bool dfs(int src, std::vector<int> adj[], int destination, std::set<int>& visited) {
        if (src == destination)
            return true;

        visited.insert(src);

        for (auto neighbor : adj[src]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, adj, destination, visited))
                    return true;
            }
        }
        return false;
    }

public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        // DFS

        // Create adjacency list
        std::vector<int> adj[n];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        std::set<int> visited;

        if (dfs(source, adj, destination, visited))
            return true;

        return false;
    }
};
