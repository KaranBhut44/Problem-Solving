class Solution {
public:
    vector<int>v;
    void inorder(TreeNode *root)
    {
        if(root == nullptr)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int n = v.size();
        int i = 0, j = n-1;
        while(i<j)
        {
            if(v[i] + v[j] == k)
                return true;
            if(v[i] + v[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};