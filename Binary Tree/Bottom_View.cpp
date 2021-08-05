class Solution {
  public:
    map<int,pair<int,int>>m;
    void traverse(Node *root,int i,int l)
    {
        if(root == nullptr)
            return;
        if(m[i].second <= l)
        {
            m[i] = {root->data,l};
        }
        traverse(root->left,i-1,l+1);
        traverse(root->right,i+1,l+1);
    }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        traverse(root,0,1);
        vector<int>v;
        for(auto i:m)
        {
            v.push_back(i.second.first);
        }
        return v;
    }
};