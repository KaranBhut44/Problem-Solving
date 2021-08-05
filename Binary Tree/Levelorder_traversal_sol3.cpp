class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root == NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>v1;
        while(q.size()>1)
        {
            TreeNode* localroot = q.front();
            q.pop();
            if(localroot)
            {
                v1.push_back(localroot->val);
                if(localroot->left)
                    q.push(localroot->left);
                if(localroot->right)
                    q.push(localroot->right);
            }
            else
            {
                q.push(NULL);
                v.push_back(v1);
                v1.clear();
            }
        }
        v.push_back(v1);
        return v;
    }
};