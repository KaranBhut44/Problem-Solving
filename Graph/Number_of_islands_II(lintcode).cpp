class DSU
{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        for (int i = 0; i < n; i++)
            size.push_back(1);
    }
    int findParent(int n)
    {
        if (parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }
    int performUnion(int u, int v)
    {
        int x = findParent(u);
        int y = findParent(v);
        if (x == y)
            return 0;
        if (size[x] > size[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
        return 1;
    }
};
class Solution
{
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators)
    {
        // write your code here

        DSU dsu(n * m);
        int condition[n][m];
        int count = 0;
        memset(condition, 0, sizeof(condition));
        vector<int> ans;
        for (auto i : operators)
        {
            if (condition[i.x][i.y] == 1)
            {
                ans.push_back(count);
                continue;
            }
            condition[i.x][i.y] = 1;
            count++;
            int arr[5] = {0, 1, 0, -1, 0};
            for (int j = 0; j < 4; j++)
            {
                int x = i.x + arr[j];
                int y = i.y + arr[j + 1];
                if (x < 0 || y < 0 || x >= n || y >= m || condition[x][y] == 0)
                    continue;
                int flag = dsu.performUnion(x * m + y, i.x * m + i.y);
                if (flag)
                    count--;
            }
            ans.push_back(count);
        }
        return ans;
    }
};