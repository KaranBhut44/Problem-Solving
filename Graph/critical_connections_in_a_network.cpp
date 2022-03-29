#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int timer = 0;
    vector<vector<int>> ans;
    void DFS(vector<int> *adj, bool *visited, int parent, int index, int *inTime, int *lowTime)
    {
        visited[index] = true;
        inTime[index] = lowTime[index] = timer++;
        for (auto nbr : adj[index])
        {
            if (parent == nbr)
                continue;
            if (visited[nbr] == false)
            {
                DFS(adj, visited, index, nbr, inTime, lowTime);

                if (lowTime[nbr] > inTime[index])
                {
                    vector<int> temp = {index, nbr};
                    ans.push_back(temp);
                }
                else
                {
                    lowTime[index] = min(lowTime[index], lowTime[nbr]);
                }
            }
            else
            {
                lowTime[index] = min(lowTime[index], lowTime[nbr]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];
        for (auto edge : connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        bool visited[n];
        int inTime[n];
        int lowTime[n];
        memset(visited, false, sizeof(visited));
        DFS(adj, visited, -1, 0, inTime, lowTime);
        return ans;
    }
};