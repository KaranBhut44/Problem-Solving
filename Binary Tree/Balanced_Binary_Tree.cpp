class Solution {
public:
    bool flag = true;
    int check(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int a = check(root->left);
        int b = check(root->right);
        if(abs(a-b) >= 2)
            flag = false;
        return 1+max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        check(root);
        return flag;
    }
};