class Solution {
public:
    int count1=0,count2=0;
    bool isValidBST(TreeNode* root,int min1=INT_MIN,int max1=INT_MAX) {
        bool opt1=true,opt2=true;
        bool c1=true,c2=true;
        
        bool c3,c4;
        if(root->val==max1)
            count1++;
        if(root->val==min1)
            count2++;
        c3 = (((max1==INT_MAX) && ((root->val) <= max1)) || (((root->val) < max1)));
        c4 = (((min1==INT_MIN) && ((root->val) >= min1)) || (((root->val) > min1)));
   
        if(count1>1)
            c3=false;
        if(count2>1)
            c4=false;
        if(root->left!=nullptr)
        {
            c1 = isValidBST(root->left,min1,root->val);
            c2 = (root->val)>((root->left)->val);
            if(c1 && c2)
                opt1=true;
            else
                opt1 = false;
        }
        if(root->right!=nullptr)
        {
            c1 = isValidBST(root->right,root->val,max1);
            c2 = (root->val)<((root->right)->val);   
            if(c1 && c2)
                opt2=true;
            else
                opt2 = false;
        }
        
        if(opt1 && opt2 && c3 && c4)
            return true;
        return false;
    }
};