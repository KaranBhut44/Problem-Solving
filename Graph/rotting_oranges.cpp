struct node
{
    int x, y, time;
    node(int a, int b, int c)
    {
        x = a;
        y = b;
        time = c;
    }
};
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<node> q;
        int n = grid.size();
        int m = grid[0].size();
        int initial = 0, recent = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(node(i, j, 0));
                }
                if (grid[i][j] != 0)
                    initial++;
            }
        }
        int arr[5] = {0, 1, 0, -1, 0};
        int max_level = 0;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            max_level = max(max_level, time);
            q.pop();
            recent++;
            for (int i = 0; i < 4; i++)
            {
                int new_x = x + arr[i];
                int new_y = y + arr[i + 1];
                if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)
                    continue;
                if (grid[new_x][new_y] == 1)
                {
                    q.push({new_x, new_y, time + 1});
                    grid[new_x][new_y] = 2;
                }
            }
        }
        if (initial != recent)
            return -1;
        return max_level;
    }
};