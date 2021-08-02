#include<bits/stdc++.h>
void traverse(Node *root,vector<Node *>&v)
{
    if(root == nullptr)
        return;
    traverse(root->left,v);
    v.push_back(root);
    traverse(root->right,v);
}
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<Node *>v;
    traverse(root,v);
    int n = v.size();
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(v[i]->key == key)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        if(v[0]->key > key)
        {
            pre = nullptr;
            suc = v[0];
            return;
        }
        if(v[n-1]->key < key)
        {
            pre = v[n-1];
            suc = nullptr;
            return;
        }
        for(int i=1;i<n;i++)
        {
            if(v[i-1]->key < key && v[i]->key > key)
            {
                pre = v[i-1];
                suc = v[i];
                return;
            }
        }
    }
    if(index == 0)
        pre = nullptr;
    else
        pre = v[index-1];
    if(index == n-1)
        suc = nullptr;
    else 
        suc = v[index+1];

// Your code goes here

}