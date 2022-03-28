class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> adj[V];
        for(auto edge:prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
	    queue<int>q;
	    int count = 0;
	    int indegree[V];
        memset(indegree,0,sizeof(indegree));
	    for(int i=0;i<V;i++)
	    {
	        for(auto j:adj[i])
	        {
	            indegree[j]++;
	        }
	    }
	    bool visited[V];
	    memset(visited,false,sizeof(visited));
	    for(int i=0;i<V;i++)
	    {
	       if(indegree[i] == 0)
	       {
	           visited[i] = true;
	           q.push(i);
	       }
	    }
	    vector<int>ans;
	    while(!q.empty())
	    {
	        int vertex = q.front();
	        q.pop();
            count++;
	        ans.push_back(vertex);
	        for(auto i:adj[vertex])
	        {
	            indegree[i]--;
	            if(indegree[i] == 0)
	            {
	                q.push(i);
	                visited[i] = 0;
	            }
	        }
	    }
        if(count != V)
            return {};
	    return ans;
    }
};
