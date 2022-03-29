class Solution
{
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> adj, int S)
    {
        // Code here
        vector<int> dist;
        for (int i = 0; i < V; i++)
        {
            dist.push_back(1e8);
        }
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto edge : adj)
            {
                if (dist[edge[1]] > dist[edge[0]] + edge[2] && dist[edge[0]] != (int)1e8)
                {
                    dist[edge[1]] = dist[edge[0]] + edge[2];
                }
            }
        }
        return dist;
    }
};