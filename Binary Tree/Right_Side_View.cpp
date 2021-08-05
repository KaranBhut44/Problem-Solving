class Solution {
public:
    map<int,int>m;
    void traverse(TreeNode *root,int l)
    {
        if(root == nullptr)
            return;
        m[l] = root->val;
        traverse(root->left,l+1);
        traverse(root->right,l+1);
    }   
    vector<int> rightSideView(TreeNode* root) {
        traverse(root,1);
        vector<int>v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        return v;
    }
};