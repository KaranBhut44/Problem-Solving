class Solution {
public:
    vector<pair<TreeNode*,int>>v1;
    void BFS(TreeNode *root)
    {
        if(root == nullptr)
            return;
        int level = 1;
        queue<pair<TreeNode *,int>> q;
        q.push({root,level});
        while(!q.empty())
        {
            TreeNode *root1 = q.front().first;
            level = q.front().second;
            v1.push_back({root1,level});
            q.pop();
            if(root1->left!= nullptr)
                q.push({root1->left,level+1});
            if(root1->right!=nullptr)
                q.push({root1->right,level+1});
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        BFS(root);
        int level=1;
        vector<int>v2;
        for(auto i:v1)
        {
            if(i.second == level)
            {
                v2.push_back(i.first->val);
            }
            else
            {
                v.push_back(v2);
                v2.clear();
                level++;
                v2.push_back(i.first->val);
            }
        }
        if(!v2.empty())
            v.push_back(v2);
        return v;
    }
};
