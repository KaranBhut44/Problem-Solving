class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        while(true)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            k--;
            if(k == 0)
                return root->val;
            root = root->right;
        }
    }
};