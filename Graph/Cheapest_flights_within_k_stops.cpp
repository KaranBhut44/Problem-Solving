class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> dist;
        for (int i = 0; i < n; i++)
        {
            dist.push_back(1e8);
        }
        dist[src] = 0;
        for (int i = 0; i < k + 1; i++)
        {
            vector<int> new_dist(dist);
            for (auto edge : flights)
            {
                new_dist[edge[1]] = min(new_dist[edge[1]], dist[edge[0]] + edge[2]);
            }
            dist = new_dist;
        }

        if (dist[dst] == (int)1e8)
            return -1;
        return dist[dst];
    }
};