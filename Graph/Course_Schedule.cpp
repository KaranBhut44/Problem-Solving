class Solution {
public:
    bool DFS(int index,bool *v1,bool *v2, vector<int> *adj)
    {
        v1[index] = true;
        v2[index] = true;
        for(auto nbr:adj[index])
        {
            if(v2[nbr] == true)
                return true;

            if(v1[nbr] == false && DFS(nbr,v1,v2,adj))
                return true;
        }
        v2[index] = false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        bool visited[V], samePath[V];
        memset(visited,false,sizeof(visited));
        memset(samePath,false,sizeof(samePath));
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                if(DFS(i,visited,samePath,adj))
                    return true;

                memset(samePath, false, sizeof(samePath));
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto edge:prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        if(isCyclic(numCourses,adj))
            return false;
        return true;
    }
};
