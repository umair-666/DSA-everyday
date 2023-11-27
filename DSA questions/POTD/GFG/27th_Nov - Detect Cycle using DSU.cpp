// Detect Cycle using DSU
// https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1


class Solution
{
    vector<int> parent;
    vector<int> Rank;
    int Get(vector<int> &parent, int a)
    {
        return parent[a] == a ? a : (parent[a] = Get(parent, parent[a]));
    }

    void Union(vector<int> &parent, vector<int> &Rank, int a, int b)
    {
        if (Rank[a] == Rank[b]) Rank[a]++;
        if (Rank[a] < Rank[b])parent[a] = b;
        else parent[b] = a;
    }
    
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	      parent.resize(V);
        Rank.resize(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;
        
        for (int u = 0; u < V; u++)
        {
            for (auto &v : adj[u])
            {
                if (u < v) // This step is much needed basically we are traversing graph as direceted  graph 
                {
                    int a = Get(parent, u);
                    int b = Get(parent, v);
                    if (a == b) return 1; // if we find that they have same parent
                    Union(parent, Rank, a, b);
                }
            }
        }
        return 0;
	}
};
