#include <bits/stdc++.h>
using namespace std;

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
    bool performUnion(int u, int v)
    {
        int x = findParent(u);
        int y = findParent(v);
        if (x == y)
            return false;
        if (size[x] > size[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
        return true;
    }
};

int main()
{
    int n;
    cin >> n;
    DSU dsu(n + 1);
    vector<pair<int, int>> remove;
    vector<pair<int, int>> add;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        int flag = dsu.performUnion(u, v);
        if (flag == false)
        {
            remove.push_back({u, v});
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(dsu.findParent(i));
    }
    vector<int> v;
    for (auto i : s)
    {
        v.push_back(i);
    }
    int k = v.size();
    for (int i = 1; i < k; i++)
    {
        add.push_back({v[0], v[i]});
    }
    int t = remove.size();
    cout << t << endl;
    int index = 0;
    while (t--)
    {
        cout << remove[index].first << " " << remove[index].second << " " << add[index].first << " " << add[index].second << endl;
        index++;
    }
    return 0;
}