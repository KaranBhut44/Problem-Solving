class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    queue<int>q;
	    
	    int indegree[V]{0};
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
	    
	    return ans;
	}
};
