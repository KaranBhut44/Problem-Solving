#define ll long long
class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 0});
        ll numWays[n];
        memset(numWays, 0, sizeof(numWays));
        ll dist[n];
        for (int i = 0; i < n; i++)
        {
            dist[i] = LLONG_MAX;
        }
        dist[0] = 0;
        numWays[0] = 1;
        vector<pair<int, ll>> adj[n];
        for (auto road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        while (!pq.empty())
        {
            ll w = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            for (auto road : adj[v])
            {
                if (dist[road.first] > w + road.second)
                {
                    dist[road.first] = w + road.second;
                    numWays[road.first] = numWays[v] % mod;
                    pq.push({dist[road.first], road.first});
                }
                else if (dist[road.first] == w + road.second)
                {
                    numWays[road.first] = (numWays[road.first] + numWays[v]) % mod;
                }
            }
        }
        return numWays[n - 1];
    }
};