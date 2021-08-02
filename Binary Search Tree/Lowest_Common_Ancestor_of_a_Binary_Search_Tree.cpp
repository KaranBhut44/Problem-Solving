class Solution {
public:
    vector<TreeNode*> search(TreeNode* root, TreeNode* node,vector<TreeNode*>v)
    {
        v.push_back(root);
        if(root == node)
            return v;
        if(root->val < node->val)
            return search(root->right,node,v);
        return search(root->left,node,v);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1 = search(root,p,{});
        vector<TreeNode*>v2 = search(root,q,{});
        int index = 0;
        int n = min(v1.size(),v2.size());
        while(index<n && v1[index] == v2[index])
            index++;
        index--;
        return v1[index];
    }
};