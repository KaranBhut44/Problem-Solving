class Solution {
public:
    vector<int> v;
    void traverse(TreeNode *root)
    {
        if(root == nullptr)
            return;
        traverse(root->left);
        v.push_back(root->val);
        traverse(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return v;
    }
};