stack<int> s;
bool DFS(TreeNode *root, int value)
{
    
    if(root==nullptr)
        return false;
   
    if(root->val == value)
    {
        s.push(value);
        return true;
    }
    
    s.push(root->val);
    if(DFS(root->left,value))
        return true;
    if(DFS(root->right,value))
        return true;
    s.pop();
    return false;
}
TreeNode* fun(TreeNode *temp,int LCA)
{
    if(temp->val == LCA)
        return temp;
    if(temp->left!=nullptr)
    {   
        TreeNode * ptr = fun(temp->left,LCA);
        if(ptr!=nullptr)
            return ptr;
    }
    if(temp->right!=nullptr)
    {   
        TreeNode * ptr = fun(temp->right,LCA);
        if(ptr!=nullptr)
            return ptr;
    }
    return nullptr;
}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>v1,v2;
        
        DFS(root,p->val);
        while (!s.empty()) {
            v1.push_back(s.top());
            s.pop();
        }
        
        DFS(root,q->val);
        while (!s.empty()) {
            v2.push_back(s.top());
            s.pop();
        }
        
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int len = min(v1.size(),v2.size());
        int LCA=0;
        for(int i=0;i<len;i++)
        {
            if(v1[i]==v2[i])
            {
                LCA = v1[i];
            }
            else
            {
                break;
            }
        }
        TreeNode *temp = root;
        return fun(temp,LCA);
    }
};