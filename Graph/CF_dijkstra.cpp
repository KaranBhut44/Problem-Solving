#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<ll, int>> adj[n + 1];

    ll dist[n + 1];
    for (int i = 0; i <= n; i++)
        dist[i] = LLONG_MAX;
    dist[1] = 0;

    int parent[n + 1];
    for (int i = 0; i <= n; i++)
        parent[i] = -1;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        ll w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (auto nbr : adj[v])
        {
            if (dist[nbr.second] > w + nbr.first)
            {
                dist[nbr.second] = w + nbr.first;
                parent[nbr.second] = v;
                pq.push({-dist[nbr.second], nbr.second});
            }
        }
    }
    vector<int> path;
    path.push_back(n);
    int node = n;
    while (parent[node] != -1)
    {
        path.push_back(parent[node]);
        node = parent[node];
    }
    if ((int)path.size() == 1)
    {
        cout << -1;
    }
    else
    {
        reverse(path.begin(), path.end());
        for (auto i : path)
            cout << i << " ";
    }

    return 0;
}