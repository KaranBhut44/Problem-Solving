class Solution
{
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: the shortest distance for the ball to stop at the destination
     */
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        // write your code here
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {start[0], start[1]}});
        int n = maze.size();
        int m = maze[0].size();
        int dist[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dist[i][j] = INT_MAX;
            }
        }
        while (!pq.empty())
        {
            int w = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            int arr[5] = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int x1 = x;
                int y1 = y;
                int count = w;
                while (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && maze[x1][y1] == 0)
                {
                    x1 += arr[i];
                    y1 += arr[i + 1];
                    count++;
                }
                x1 -= arr[i];
                y1 -= arr[i + 1];
                count--;
                if (dist[x1][y1] > count)
                {
                    pq.push({-count, {x1, y1}});
                    dist[x1][y1] = count;
                }
            }
        }
        if (dist[destination[0]][destination[1]] == INT_MAX)
            return -1;
        return dist[destination[0]][destination[1]];
    }
};