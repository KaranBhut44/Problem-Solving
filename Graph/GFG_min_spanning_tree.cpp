class DSU
{
public:
    vector<int> parent, size;
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int findParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void performUnion(int u, int v)
    {
        int x = findParent(u);
        int y = findParent(v);
        if (x == y)
            return;
        if (size[x] >= size[y])
            parent[y] = x;
        else
            parent[x] = y;
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        DSU dsu(V);
        set<pair<int, pair<int, int>>> s;
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : adj[i])
            {
                s.insert({nbr[1], {min(i, nbr[0]), max(i, nbr[0])}});
            }
        }
        for (auto edge : s)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;
            if (dsu.findParent(u) != dsu.findParent(v))
            {
                dsu.performUnion(u, v);
                ans += w;
            }
        }
        return ans;
    }
};