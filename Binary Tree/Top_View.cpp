map<int,pair<int,int>>m;
    void traverse(Node *root,int i,int l)
    {
        if(root == nullptr)
            return;
        if(m[i].second > l || m[i].second == 0)
        {
            m[i] = {root->data,l};
        }
        traverse(root->left,i-1,l+1);
        traverse(root->right,i+1,l+1);
    }
    void topView(Node * root) {
        traverse(root,0,1);
        for(auto i:m)
        {
            cout<<i.second.first<<" ";
        }
    }