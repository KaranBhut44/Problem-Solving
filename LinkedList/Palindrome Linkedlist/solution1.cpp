class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *t=head;
        vector<int>v;
        while(t!=nullptr)
        {
            v.push_back(t->val);
            t=t->next;
        }
        for(int i=0;i<v.size()/2;i++)
        {
            if(v[i]!=v[v.size()-1-i])
                return false;
        }
        return true;
    }
};