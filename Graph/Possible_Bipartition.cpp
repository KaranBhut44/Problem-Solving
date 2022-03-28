class Solution {
public:
    bool DFS(int *visited, vector<int> *adj, int index,int c)
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(auto edge: dislikes)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int visited[n+1];
        for(int i=1;i<=n;i++)
            visited[i] = 0;
        
        for(int i=1;i<=n;i++)
        {
            if(visited[i] == 0)
            {
                if(DFS(visited,adj,i,0) == false)
                    return false;
            }
        }
        return true;
    }
};
