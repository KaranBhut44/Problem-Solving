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
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        // write your code here
        int n = rooms.size();
        int m = rooms[0].size();
        queue<node> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push(node(i, j, 0));
                }
            }
        }
        while (!q.empty())
        {
            int old_x = q.front().x;
            int old_y = q.front().y;
            int time = q.front().time;
            q.pop();
            int arr[5] = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int x = old_x + arr[i];
                int y = old_y + arr[i + 1];
                if (x < 0 || y < 0 || x >= n || y >= m)
                    continue;
                if (rooms[x][y] == 2147483647)
                {
                    q.push(node(x, y, time + 1));
                    rooms[x][y] = time + 1;
                }
            }
        }
    }
};