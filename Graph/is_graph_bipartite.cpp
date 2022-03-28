class Solution {
public:
    bool DFS(int *visited, vector<vector<int>> &adj, int index,int c)
    {
        visited[index] = c;
        for(auto nbr:adj[index])
        {
            if(visited[nbr] == 0)
            {
                if(DFS(visited, adj, nbr, c+1) == false)
                    return false;
            }
            else
            {
                if(visited[nbr]%2 == c%2)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int visited[n];
        for(int i=0;i<n;i++)
            visited[i] = 0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                if(DFS(visited,graph,i,0) == false)
                    return false;
            }
        }
        return true;
    }
};
