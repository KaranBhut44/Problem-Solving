class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        // write your code here
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        int n = maze.size();
        int m = maze[0].size();
        bool **visited = new bool*[n];
        for(int i=0;i<n;i++)
        {
            visited[i] = new bool[m];
            for(int j=0;j<m;j++)
            {
                visited[i][j] = false;
            }
        }
        visited[start[0]][start[1]] = true;
        while(!q.empty())
        {
            int old_x = q.front().first;
            int old_y = q.front().second;
            if(old_x == destination[0] && old_y == destination[1])
                return true;
            q.pop();
            int arr[5] = {0,1,0,-1,0};
            for(int i=0;i<4;i++)
            {
                int x = old_x;
                int y = old_y;
                
                while(x>=0 && y>=0 && x<=n-1 && y<=m-1 && maze[x][y] == 0)
                {
                    y += arr[i+1];
                    x += arr[i];
                }
                y -= arr[i+1];
                x -= arr[i];
                if(visited[x][y] == false)
                {
                    q.push({x,y});
                    visited[x][y] = true;
                }
            }  
        }
        return false;
    }
};
