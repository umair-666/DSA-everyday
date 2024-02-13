// Clone an Undirected Graph
// https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        // If the current node has already been visited, return its clone
        if (visited.find(node) != visited.end())
            return visited[node];

        // Create a clone for the current node
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // Clone the neighbors recursively
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, visited));
        }

        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node;

        unordered_map<Node*, Node*> visited; // Map to store visited nodes and their clones
        return dfs(node, visited);
    }

};
