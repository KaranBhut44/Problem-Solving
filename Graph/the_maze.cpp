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
        int x1 = start[0];
        int y1 = start[1];
        int x2 = destination[0];
        int y2 = destination[1];
        queue<pair<int,int>>q;
        q.push({x1,y1});
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
        visited[x1][y1] = true;
        while(!q.empty())
        {
            int old_x = q.front().first;
            int old_y = q.front().second;
            //cout<<old_x<<" "<<old_y<<endl;
            if(old_x == x2 && old_y == y2)
                return true;
            q.pop();
            //left
            int x = old_x;
            int y = old_y;
            while(maze[x][y] != 1 && y!=0)
            {
                y--;
            }
            if(maze[x][y] == 1)
            {
                y++;
                if(old_y > y && visited[old_x][y] == false)
                {
                    //cout<<old_x<<" "<<old_y<<" left1 "<<old_x<<" "<<y<<endl;
                    q.push({old_x,y});
                    visited[old_x][y] = true;
                }
            }
            else if(visited[old_x][y] == false)
            {
                //cout<<old_x<<" "<<old_y<<" left2 "<<old_x<<" "<<y<<endl;
                visited[old_x][y] = true;
                q.push({old_x,y});
            }
            //top
            x = old_x;
            y = old_y;
            while(maze[x][y] != 1 && x!=0)
            {
                x--;
            }
            if(maze[x][y] == 1)
            {
                x++;
                if(old_x > x && visited[x][old_y] == false)
                {
                    //cout<<old_x<<" "<<old_y<<" top1 "<<x<<" "<<old_y<<endl;
                    q.push({x,old_y});
                    visited[x][old_y] = true;
                }
            }
            else if(visited[x][old_y] == false)
            {
                //cout<<old_x<<" "<<old_y<<" top2 "<<x<<" "<<old_y<<endl;
                visited[x][old_y] = true;
                q.push({x,old_y});
            }
            //right
            x = old_x;
            y = old_y;
            while(maze[x][y] != 1 && y!=m-1)
            {
                y++;
            }
            if(maze[x][y] == 1)
            {
                y--;
                if(old_y < y && visited[old_x][y] == false)
                {
                    //cout<<old_x<<" "<<old_y<<" right1 "<<old_x<<" "<<y<<endl;
                    q.push({old_x,y});
                    visited[old_x][y] = true;
                }
            }
            else if(visited[old_x][y] == false)
            {
                //cout<<old_x<<" "<<old_y<<" right2 "<<old_x<<" "<<y<<endl;
                visited[old_x][y] = true;
                q.push({old_x,y});
            }
            //bottom
            x = old_x;
            y = old_y;
            while(maze[x][y] != 1 && x!=n-1)
            {
                x++;
            }
            if(maze[x][y] == 1)
            {
                x--;
                if(old_x < x && visited[x][old_y] == false)
                {
                    //cout<<old_x<<" "<<old_y<<" bottom1 "<<x<<" "<<y<<endl;
                    q.push({x,old_y});
                    visited[x][old_y] = true;
                }
            }
            else if(visited[x][old_y] == false)
            {
                //cout<<old_x<<" "<<old_y<<" bottom2 "<<x<<" "<<old_y<<endl;
                visited[x][old_y] = true;
                q.push({x,old_y});
            }
        }
        return false;
    }
};
