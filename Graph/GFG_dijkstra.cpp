class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>> pq;
        pq.push({0, S});
        vector<int> dist;
        for (int i = 0; i < V; i++)
        {
            dist.push_back(INT_MAX);
        }
        dist[S] = 0;
        while (!pq.empty())
        {
            int w = -pq.top().first;
            int v = pq.top().second;
            pq.pop();
            for (auto pairs : adj[v])
            {
                if (pairs[1] + w < dist[pairs[0]])
                {
                    dist[pairs[0]] = pairs[1] + w;
                    pq.push({-dist[pairs[0]], pairs[0]});
                }
            }
        }
        return dist;
    }
};