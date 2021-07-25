class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr && l2==nullptr)
            return nullptr;
        ListNode *head = new ListNode();
        ListNode *prev = head;
        ListNode *t1=l1,*t2=l2;
        int count=0;
        while(t1!=nullptr && t2!=nullptr)
        {
            ListNode *t3 = new ListNode();
            if(count==0)
            {
                t3=prev;
            }
            else
            {
                prev->next =t3;
            }
            if(t1->val<=t2->val)
            {
                t3->val = t1->val;
                t1=t1->next;
            }
            else
            {
                t3->val = t2->val;
                t2=t2->next;
            }
            if(count!=0)
                prev=prev->next;
            count++;
        }
        while(t1!=nullptr)
        {
            ListNode *t3 = new ListNode(t1->val);
            if(count==0)
            {
                prev->val=t1->val;
            }
            else
            {
                prev->next=t3;
                prev=prev->next;
            }
            count++;
            t1=t1->next;
        }
        while(t2!=nullptr)
        {
            ListNode *t3 = new ListNode(t2->val);
            if(count==0)
            {
                prev->val=t2->val;
            }
            else
            {
                prev->next=t3;
                prev=prev->next;
            }
            count++;
            t2=t2->next;
        }
        return head;
    }
};