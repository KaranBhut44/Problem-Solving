class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *t = head;
        if(head==nullptr)
            return nullptr;
        vector<int>v;
        while(t!=nullptr)
        {
            v.push_back(t->val);
            t=t->next;
        }
        reverse(v.begin(),v.end());
        ListNode *p =new ListNode();
        ListNode *head1=p;
        int count=0;
        for(auto i:v)
        {
            if(count==0)
            {
                p->val = i;
            }
            else
            {
                ListNode *t = new ListNode();
                t->val = i;
                p->next=t;
                p=p->next;
            }
            
            count++;
        }
        return head1;
    }
};