class Solution {
public:
    vector<int>v1;
    int find_height(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int left = find_height(root->left);
        int right = find_height(root->right);
        return max(left,right) + 1;
    }
    void kthlevel(TreeNode *root,int height)
    {
        if(root == nullptr)
            return;
        if(height == 1)
        {
            v1.push_back(root->val);
            return;
        }
        kthlevel(root->left,height-1);
        kthlevel(root->right,height-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int height = find_height(root);
        vector<vector<int>>v;
        for(int i=1;i<=height;i++)
        {
            kthlevel(root,i);
            v.push_back(v1);
            v1.clear();
        }
        return v;
    }
};